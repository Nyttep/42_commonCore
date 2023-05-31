#!/bin/sh

# Faire un healthcheck pour attendre que le service mariadb soit up
sleep 12

if [ ! -f /var/www/wordpress/wp-config.php ]; then
	echo "Configuring wordpress..."
	echo "${SQL_DATABASE}<->${SQL_USER}<->${SQL_PASSWORD}"
	wp config create --allow-root \
		--dbname=${SQL_DATABASE} \
		--dbuser=${SQL_USER} \
		--dbpass=${SQL_PASSWORD} \
		--dbhost=mariadb --path='/var/www/wordpress'
sleep 4
wp core install     --url=$DOMAIN_NAME --title=Pdubois --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PSWD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root --path='/var/www/wordpress'
wp user create      --allow-root --role=author $WP_USER $WP_USER_EMAIL --user_pass=$WP_USER_PSWD --path='/var/www/wordpress' >> /log.txt
fi

/usr/sbin/php-fpm7.3 -F
