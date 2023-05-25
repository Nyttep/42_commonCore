#!/bin/bash
sleep 10
if [ ! -d /var/www/wordpress/wp-config.php ]
then
	wp config create --allow-root --dbname=$SQL_DATABASE --dbuser=$SQL_USER --dbpass=$SQL_PASSWORD --dbhost=mariadb:3306 --path='/var/www/wordpress'
	wp core install --allow-root --path=/var/www/wordpress --url=$DOMAIN_NAME --title=Pdubois --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PSWD --admin_email=$WP_ADMIN_EMAIL --skip-email
	wp user create $WP_USER $WP_USER_EMAIL --allow-root --path=/var/www/wordpress --user_pass=$WP_USER_PSWD
fi
if [ ! -d /run/php ]
then
	mkdir -p /run/php
fi
/usr/sbin/php-fpm7.3 -F
