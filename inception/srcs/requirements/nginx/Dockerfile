FROM	alpine:3.17

RUN	apk update && \
	apk upgrade && \
	apk add nginx && \
	apk add openssl

RUN	mkdir -p /etc/nginx/tsl && \
	mkdir -p /var/run/nginx
RUN	openssl req -x509 -nodes -out /etc/nginx/tsl/inception.crt -keyout /etc/nginx/tsl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=pdubois.42.fr/UID=pdubois"
RUN	chmod 755 /var/www/html && \
	chown -R www-data:www-data /var/www/html

COPY ./conf/nginx.conf /etc/nginx/nginx.conf

CMD ["nginx", "-g", "daemon off;"]
