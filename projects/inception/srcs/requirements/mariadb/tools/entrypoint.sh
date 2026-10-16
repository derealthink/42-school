#!/bin/sh
set -eu

: "${MYSQL_DATABASE:?MYSQL_DATABASE must be set}"
: "${MYSQL_USER:?MYSQL_USER must be set}"
: "${MYSQL_ROOT_PASSWORD_FILE:?MYSQL_ROOT_PASSWORD_FILE must be set}"
: "${MYSQL_PASSWORD_FILE:?MYSQL_PASSWORD_FILE must be set}"

MYSQL_ROOT_PASSWORD=$(cat "$MYSQL_ROOT_PASSWORD_FILE")
MYSQL_PASSWORD=$(cat "$MYSQL_PASSWORD_FILE")
MYSQL_ROOT_PASSWORD_SQL=$(printf "%s" "$MYSQL_ROOT_PASSWORD" | sed "s/'/''/g")
MYSQL_PASSWORD_SQL=$(printf "%s" "$MYSQL_PASSWORD" | sed "s/'/''/g")

mkdir -p /run/mysqld /var/lib/mysql
chown -R mysql:mysql /run/mysqld /var/lib/mysql

# Create MariaDB's system tables only on the first run of the persistent volume.
if [ ! -d /var/lib/mysql/mysql ]; then
	mariadb-install-db --user=mysql --datadir=/var/lib/mysql --skip-test-db >/dev/null
fi

if [ ! -f /var/lib/mysql/.inception_initialized ]; then
	# A local temporary server lets us create the database before opening port 3306.
	mariadbd --user=mysql --skip-networking --socket=/run/mysqld/mysqld.sock --pid-file=/run/mysqld/mysqld.pid &
	mariadb_pid="$!"

	for _ in $(seq 1 60); do
		mariadb-admin --socket=/run/mysqld/mysqld.sock ping --silent && break
		sleep 1
	done

	mariadb-admin --socket=/run/mysqld/mysqld.sock ping --silent

	# Grant WordPress access and prevent anonymous or passwordless root access.
	mariadb --socket=/run/mysqld/mysqld.sock -uroot <<-EOSQL
		CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\` CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
		CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD_SQL}';
		GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
		ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD_SQL}';
		DELETE FROM mysql.user WHERE User='';
		DROP DATABASE IF EXISTS test;
		FLUSH PRIVILEGES;
EOSQL

	mariadb-admin --socket=/run/mysqld/mysqld.sock -uroot -p"$MYSQL_ROOT_PASSWORD" shutdown
	wait "$mariadb_pid"
	touch /var/lib/mysql/.inception_initialized
fi

exec "$@"
