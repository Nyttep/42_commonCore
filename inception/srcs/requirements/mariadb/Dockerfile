FROM	debian:buster

RUN	apt-get update -y && \
	apt-get upgrade -y && \
	apt-get install mariadb-server -y

COPY	conf/mariadb.cnf /etc/mysql/mariadb.conf.d/mariadb.cnf
COPY	tools/mariadb_script.sh script.sh

RUN chmod +x script.sh

CMD	["bash", "./script.sh"]
