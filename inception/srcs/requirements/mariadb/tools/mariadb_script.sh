#!/bin/bash
service mysql start
echo mysql -u root -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$SQL_ROOT_PASSWORD';"
mysql -u root -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$SQL_ROOT_PASSWORD';"
echo mysql -u root -p$SQL_ROOT_PASSWORD -e "FLUSH PRIVILEGES;"
mysql -u root -p$SQL_ROOT_PASSWORD -e "FLUSH PRIVILEGES;"
echo mysql -u root -p$SQL_ROOT_PASSWORD -e "CREATE DATABASE IF NOT EXISTS \`$SQL_DATABASE\`;"
mysql -u root -p$SQL_ROOT_PASSWORD -e "CREATE DATABASE IF NOT EXISTS \`$SQL_DATABASE\`;"
echo mysql -u root -p$SQL_ROOT_PASSWORD -e "CREATE USER IF NOT EXISTS \`$SQL_USER\`@'localhost' IDENTIFIED BY '$SQL_PASSWORD';"
mysql -u root -p$SQL_ROOT_PASSWORD -e "CREATE USER IF NOT EXISTS \`$SQL_USER\`@'localhost' IDENTIFIED BY '$SQL_PASSWORD';"
echo mysql -u root -p$SQL_ROOT_PASSWORD -e "GRANT ALL PRIVILEGES ON \`$SQL_DATABASE\`.* TO \`$SQL_USER\`@'%' IDENTIFIED BY '$SQL_PASSWORD';"
mysql -u root -p$SQL_ROOT_PASSWORD -e "GRANT ALL PRIVILEGES ON \`$SQL_DATABASE\`.* TO \`$SQL_USER\`@'%' IDENTIFIED BY '$SQL_PASSWORD';"
echo mysqladmin -u root -p$SQL_ROOT_PASSWORD shutdown
mysqladmin -u root -p$SQL_ROOT_PASSWORD shutdown
exec mysqld_safe

