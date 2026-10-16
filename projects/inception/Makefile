LOGIN := uponci
DATA_DIR := /home/$(LOGIN)/data
COMPOSE := docker compose -f srcs/docker-compose.yml --env-file srcs/.env

.PHONY: all prepare build up down stop restart rebuild clean fclean re reset ps logs

all: up

prepare:
	mkdir -p $(DATA_DIR)/mariadb $(DATA_DIR)/wordpress

build: prepare
	$(COMPOSE) build

up: prepare
	$(COMPOSE) up -d --build

down:
	$(COMPOSE) down

stop:
	$(COMPOSE) stop

# Restart the existing containers without recreating them or touching stored data.
restart:
	$(COMPOSE) restart

# Recreate containers and images while keeping the database and WordPress volumes.
rebuild: prepare
	$(COMPOSE) down --remove-orphans
	$(COMPOSE) up -d --build

clean:
	$(COMPOSE) down --remove-orphans

# Remove Compose containers and images, but deliberately retain persistent data.
fclean:
	$(COMPOSE) down --rmi all --remove-orphans

re: rebuild

# Explicit factory reset. This is the only target that deletes site/database data.
reset:
	@printf 'This permanently deletes all WordPress and MariaDB data. Type RESET to continue: '; \
	read answer; \
	[ "$$answer" = "RESET" ] || { echo "Reset cancelled."; exit 1; }; \
	$(COMPOSE) down -v --remove-orphans; \
	docker run --rm -v $(DATA_DIR):/data debian:bookworm \
		sh -c 'rm -rf /data/mariadb /data/wordpress'; \
	$(MAKE) prepare

ps:
	$(COMPOSE) ps

logs:
	$(COMPOSE) logs -f
