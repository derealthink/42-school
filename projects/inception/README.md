*This project has been created as part of the 42 curriculum by uponci.*

# Inception

## Description

Inception builds a small, reproducible web infrastructure inside a virtual
machine with Docker Compose. It runs three services, each in its own container
and built from a project Dockerfile based on Debian Bookworm:

- **NGINX** is the only public entry point. It listens on host port `443`,
  terminates TLS, serves static files, and forwards PHP requests to WordPress
  over FastCGI.
- **WordPress + PHP-FPM** provides the website and creates the configured
  administrator and author accounts on the first run. It does not contain
  NGINX.
- **MariaDB** stores the WordPress database. It does not contain NGINX.

The browser-facing request path is:

```text
Browser -- HTTPS/TLS 1.2 or 1.3 --> NGINX -- FastCGI --> WordPress/PHP-FPM
                                                       |
                                                       +-- MariaDB protocol --> MariaDB
```

Only NGINX publishes a host port. The other services communicate by service
name on the private, user-defined `inception` bridge network. The `wordpress`
volume is shared read-only with NGINX so it can serve the site files, while the
`mariadb` volume is visible only to MariaDB. Both named volumes persist data
under `/home/uponci/data` on the host, so rebuilding containers does not erase
the site or database. Each container runs its main daemon in the foreground as
PID 1 and uses an `always` restart policy.

### Project sources

```text
.
├── Makefile
├── secrets/                         # local secret files mounted by Compose
└── srcs/
    ├── .env                         # non-secret configuration
    ├── docker-compose.yml           # services, network, volumes, secrets
    └── requirements/
        ├── mariadb/
        │   ├── Dockerfile
        │   ├── conf/50-server.cnf
        │   └── tools/entrypoint.sh
        ├── nginx/
        │   ├── Dockerfile
        │   ├── conf/default.conf.template
        │   └── tools/entrypoint.sh
        └── wordpress/
            ├── Dockerfile
            ├── conf/www.conf
            └── tools/entrypoint.sh
```

The Dockerfiles install only the packages needed by their service. Entrypoint
scripts perform idempotent first-run initialization, then replace themselves
with the service daemon using `exec`. WordPress waits until MariaDB accepts
connections before downloading and installing the site. NGINX generates a
self-signed certificate and enables TLS 1.2 and 1.3 only.

### Main design choices

| Choice | Comparison and reason |
| --- | --- |
| Docker instead of virtual machines | A VM emulates hardware and runs a complete guest OS and kernel. A container shares the host kernel while isolating its processes, filesystem, and network. Containers are therefore smaller and start faster; VMs generally provide a stronger isolation boundary and can run a different kernel. This project uses a VM as the host required by the subject, then Docker containers for reproducible service isolation inside it. |
| Secrets instead of environment variables for passwords | Environment variables are convenient for non-sensitive settings but are inherited by processes and are easy to expose through configuration or inspection. Compose secrets grant a service access to an explicit file under `/run/secrets`. This project keeps domain, database name, and usernames in `srcs/.env`, while passwords are supplied through secret files. |
| Docker network instead of host networking | Host networking removes network isolation and makes a container use the host network stack directly. The user-defined bridge keeps internal ports private, provides DNS resolution by service name (`mariadb`, `wordpress`), and publishes only NGINX port `443`. |
| Docker named volumes instead of direct service bind mounts | A named volume has a Docker-managed identity and lifecycle and is declared once in Compose. A bind mount directly couples a container path to an arbitrary host path. The services consume named volumes; the local volume driver places their persistent data at the subject-required `/home/uponci/data` paths. |

## Instructions

### Requirements

- A Linux virtual machine with Docker Engine, the Docker Compose plugin, and
  GNU Make installed
- `sudo` access to create `/home/uponci/data`
- The host entry `127.0.0.1 uponci.42.fr` (use the VM IP instead of
  `127.0.0.1` when browsing from another machine)

Add the domain locally if it is not already present:

```sh
echo '127.0.0.1 uponci.42.fr' | sudo tee -a /etc/hosts
```

Copy each `secrets/*.txt.example` file to the same name without `.example` and replace its placeholder with a strong local password. These real secret files are ignored by Git.

Review `srcs/.env`, then create the following secret files with strong values,
one value per file and no surrounding quotes:

```text
secrets/db_root_password.txt
secrets/db_password.txt
secrets/wp_admin_password.txt
secrets/wp_user_password.txt
```

Do not commit real credentials. Ensure secret files are readable only by their
owner:

```sh
chmod 600 secrets/*.txt
```

### Build and run

From the repository root:

```sh
make
make ps
```

The first build needs network access to install Debian packages and download
WP-CLI/WordPress. Once all containers are running, open
<https://uponci.42.fr>. The certificate is self-signed, so the browser will
display a warning during local use.

Useful lifecycle targets:

```sh
make logs       # follow logs from every service
make stop       # stop containers without removing them
make restart    # restart the existing containers
make down       # stop and remove containers/network; retain persistent data
make rebuild    # rebuild and recreate containers; retain persistent data
make fclean     # also remove project images; retain persistent data
make reset      # explicitly confirmed factory reset; deletes site/database data
```

`make reset` is destructive. It is the only project target that removes the
persistent WordPress and MariaDB data.

## Testing the mandatory requirements

Run these checks from the repository root after `make`. Commands that are
expected to fail are marked explicitly.

### 1. Static structure and prohibited configuration

Confirm that all three custom Dockerfiles exist and Compose resolves correctly:

```sh
find srcs/requirements -name Dockerfile -type f -print
docker compose -f srcs/docker-compose.yml --env-file srcs/.env config
```

Inspect the submitted Dockerfiles, Compose file, Makefile, and entrypoint
scripts. There must be no host networking, links, infinite-loop keepalive
hacks, or backgrounded final daemon:

```sh
grep -RniE 'network_mode:[[:space:]]*host|network:[[:space:]]*host|links:|--link|tail[[:space:]]+-f|sleep[[:space:]]+infinity|while[[:space:]]+true' \
  Makefile srcs
```

Expected: no output. Also verify the images were built from the project and
have service-matching repository names:

```sh
docker compose -f srcs/docker-compose.yml --env-file srcs/.env images
```

### 2. Containers and network

```sh
make ps
docker network ls
docker network inspect inception
```

Expected: `nginx`, `wordpress`, and `mariadb` are running and attached to the
`inception` network. Only NGINX should publish `0.0.0.0:443->443/tcp` (and the
IPv6 equivalent, if enabled):

```sh
docker port nginx
docker port wordpress
docker port mariadb
```

### 3. NGINX, HTTPS, and TLS

HTTP must not be reachable:

```sh
curl --connect-timeout 5 -v http://uponci.42.fr
```

Expected: connection refused or timeout. HTTPS must return the configured
WordPress site rather than the installation page:

```sh
curl -kI https://uponci.42.fr
curl -ks https://uponci.42.fr | grep -i '<title'
```

The `-k` option is needed only because the certificate is self-signed. Prove
that TLS 1.2 and 1.3 succeed:

```sh
openssl s_client -connect uponci.42.fr:443 -servername uponci.42.fr -tls1_2 </dev/null
openssl s_client -connect uponci.42.fr:443 -servername uponci.42.fr -tls1_3 </dev/null
```

In each successful output, check the negotiated `Protocol`/`New` line and
cipher. Then prove that the old protocols are rejected:

```sh
openssl s_client -connect uponci.42.fr:443 -servername uponci.42.fr -tls1 </dev/null
openssl s_client -connect uponci.42.fr:443 -servername uponci.42.fr -tls1_1 </dev/null
```

Expected: both old-version handshakes fail with no peer certificate or no
negotiated cipher.

### 4. WordPress and its persistent volume

```sh
docker volume ls
docker volume inspect wordpress
docker exec wordpress wp core is-installed --path=/var/www/html --allow-root
docker exec wordpress wp user list --fields=user_login,roles --path=/var/www/html --allow-root
```

Expected: the volume inspection contains `/home/uponci/data/wordpress`;
WordPress reports success; there are at least two users; and the administrator
login contains no variation of `admin` or `administrator`.

Functional browser test:

1. Open <https://uponci.42.fr> and confirm the installation wizard is absent.
2. Sign in as the regular WordPress user and add a comment to a post.
3. Sign in at <https://uponci.42.fr/wp-admin/> with the administrator account.
4. Edit and update a page, then reload that page on the public site and confirm
   the change appears.

### 5. MariaDB and its persistent volume

```sh
docker volume inspect mariadb
```

Expected: the output contains `/home/uponci/data/mariadb`. A passwordless root
login must fail:

```sh
docker exec mariadb mariadb -uroot -e 'SELECT 1;'
```

Expected: `Access denied` and a non-zero exit status. Log in with the WordPress
database user; enter the value from `secrets/db_password.txt` only when the
interactive prompt asks for it:

```sh
docker exec -it mariadb mariadb -u wp_user -p wordpress
```

At the MariaDB prompt:

```sql
SHOW TABLES;
SELECT COUNT(*) FROM wp_posts;
SELECT COUNT(*) FROM wp_users;
EXIT;
```

Expected: the standard WordPress tables exist and the queried tables contain
rows.

### 6. Persistence after restart

Before restarting, note the edited page and comment created above. Reboot the
virtual machine, then run:

```sh
cd /path/to/inception_final
make
make ps
```

Open <https://uponci.42.fr> again. The configured site, both users, edited page,
and comment must still be present. This demonstrates that container recreation
does not erase either named volume.

## Resources

- [Docker overview](https://docs.docker.com/get-started/docker-overview/)
- [Docker Compose documentation](https://docs.docker.com/compose/)
- [Docker bridge networks](https://docs.docker.com/engine/network/drivers/bridge/)
- [Docker volumes](https://docs.docker.com/engine/storage/volumes/)
- [Docker bind mounts](https://docs.docker.com/engine/storage/bind-mounts/)
- [Docker Compose secrets](https://docs.docker.com/compose/how-tos/use-secrets/)
- [Docker Compose environment variables](https://docs.docker.com/compose/how-tos/environment-variables/)
- [NGINX HTTPS configuration](https://nginx.org/en/docs/http/configuring_https_servers.html)
- [NGINX SSL module](https://nginx.org/en/docs/http/ngx_http_ssl_module.html)
- [WordPress WP-CLI commands](https://developer.wordpress.org/cli/commands/)
- [MariaDB Server documentation](https://mariadb.com/docs/server/)
- [OpenSSL `s_client`](https://docs.openssl.org/3.0/man1/openssl-s_client/)

### Use of AI

AI was used to help draft and organize this README, explain the required
infrastructure concepts, compare the design alternatives required by the
subject, and turn the evaluation criteria into reproducible test commands. It
was also used to cross-check the documented service names, paths, ports,
Makefile targets, TLS settings, and initialization behavior against the
project files. The project owner remains responsible for reviewing, testing,
and understanding every command and technical claim.

---

Part of my [42 School project collection](../../README.md).
