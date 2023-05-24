FROM	debian:buster

RUN	apt-get update -y && \
	apt-get upgrade -y
RUN	apt-get install wget -y
RUN	apt-get install php php-fpm php-mysql mariadb-client -y
RUN	wget https://fr.wordpress.org/wordpress-6.2.2-fr_FR.tar.gz -P /var/www
RUN	cd /var/www && \
	tar -xzf *.tar.gz && \
	rm *.tar.gz
RUN	chown -R root:root /var/www/wordpress
RUN	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp

COPY ./conf/php.ini /etc/php/7.3/cli/php.ini
COPY ./tools/wp_script.sh ./script.sh

#ENTRYPOINT ["bash", "./script.sh"]
