FROM 	debian:buster
RUN		apt-get update -y
RUN		apt-get upgrade -y
RUN		apt-get install -y mariadb-server

COPY	tools/init.sh .
RUN		chmod -R 777 init.sh

EXPOSE 	3306
RUN 	rm /etc/mysql/mariadb.conf.d/50-server.cnf
COPY	./conf/50-server.cnf /etc/mysql/mariadb.conf.d
ENTRYPOINT ["bash", "init.sh"]