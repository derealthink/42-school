#!/bin/sh
set -eu

for var in DOMAIN_NAME MYSQL_DATABASE MYSQL_USER WORDPRESS_DB_HOST WORDPRESS_TITLE WORDPRESS_ADMIN_USER WORDPRESS_ADMIN_EMAIL WORDPRESS_USER WORDPRESS_USER_EMAIL; do
	eval ": \"\${$var:?$var must be set}\""
done

: "${MYSQL_PASSWORD_FILE:?MYSQL_PASSWORD_FILE must be set}"
: "${WORDPRESS_ADMIN_PASSWORD_FILE:?WORDPRESS_ADMIN_PASSWORD_FILE must be set}"
: "${WORDPRESS_USER_PASSWORD_FILE:?WORDPRESS_USER_PASSWORD_FILE must be set}"

MYSQL_PASSWORD=$(cat "$MYSQL_PASSWORD_FILE")
WORDPRESS_ADMIN_PASSWORD=$(cat "$WORDPRESS_ADMIN_PASSWORD_FILE")
WORDPRESS_USER_PASSWORD=$(cat "$WORDPRESS_USER_PASSWORD_FILE")

# Wait for the database because depends_on starts containers in order but does
# not guaranteed that MariaDB is ready to accept connections.
db_host=${WORDPRESS_DB_HOST%%:*}
db_port=${WORDPRESS_DB_HOST##*:}
[ "$db_port" != "$WORDPRESS_DB_HOST" ] || db_port=3306

for _ in $(seq 1 60); do
	mariadb-admin ping -h "$db_host" -P "$db_port" -u "$MYSQL_USER" -p"$MYSQL_PASSWORD" --silent && break
	sleep 1
done
mariadb-admin ping -h "$db_host" -P "$db_port" -u "$MYSQL_USER" -p"$MYSQL_PASSWORD" --silent

# Download and configure WordPress only when the persistent volume is empty.
if [ ! -f /var/www/html/wp-load.php ]; then
	wp core download --path=/var/www/html --force --allow-root
fi

if [ ! -f /var/www/html/wp-config.php ]; then
	wp config create \
		--path=/var/www/html \
		--dbname="$MYSQL_DATABASE" \
		--dbuser="$MYSQL_USER" \
		--dbpass="$MYSQL_PASSWORD" \
		--dbhost="$WORDPRESS_DB_HOST" \
		--skip-check \
		--allow-root
fi

# Install the site and its non-admin author account only on the first run.
if ! wp core is-installed --path=/var/www/html --allow-root >/dev/null 2>&1; then
	wp core install \
		--path=/var/www/html \
		--url="https://${DOMAIN_NAME}" \
		--title="$WORDPRESS_TITLE" \
		--admin_user="$WORDPRESS_ADMIN_USER" \
		--admin_password="$WORDPRESS_ADMIN_PASSWORD" \
		--admin_email="$WORDPRESS_ADMIN_EMAIL" \
		--skip-email \
		--allow-root

	wp user create "$WORDPRESS_USER" "$WORDPRESS_USER_EMAIL" \
		--path=/var/www/html \
		--user_pass="$WORDPRESS_USER_PASSWORD" \
		--role=author \
		--allow-root
fi

chown -R www-data:www-data /var/www/html /run/php

exec "$@"
