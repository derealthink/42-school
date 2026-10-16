FROM debian:bookworm

RUN apt-get update \
    && apt-get install -y --no-install-recommends ca-certificates gettext-base nginx openssl \
    && rm -rf /var/lib/apt/lists/*

COPY conf/default.conf.template /etc/nginx/templates/default.conf.template
COPY tools/entrypoint.sh /usr/local/bin/entrypoint.sh

RUN chmod +x /usr/local/bin/entrypoint.sh \
    && mkdir -p /etc/nginx/ssl /var/www/html /run/nginx \
    && rm -rf /var/www/html/*

EXPOSE 443

ENTRYPOINT ["entrypoint.sh"]
CMD ["nginx", "-g", "daemon off;"]
