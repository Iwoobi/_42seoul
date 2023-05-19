FROM	debian:buster
RUN		apt-get update -y
RUN		apt-get upgrade -y
RUN		apt-get install -y sendmail
RUN		apt-get -y install php7.3\
		php-fpm\
		php-mysql\
		mariadb-client\
		wget\
		curl

# wordpress-client 다운받기
RUN		curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar &&\
		chmod +x wp-cli.phar &&\
		mv wp-cli.phar /usr/local/bin/wp
COPY	./conf/www.conf			/etc/php/7.3/fpm/pool.d
RUN echo "access.log = /var/log/$pool.access.log" >> /etc/php/7.3/fpm/pool.d/www.conf
RUN mkdir -p /var/www/wordpress
RUN chown -R  www-data:www-data /var/www/wordpress/
RUN chmod 777 /var/www/wordpress/
RUN mkdir -p /run/php/
COPY tools/init.sh /var/www/wordpress
RUN chmod 777 /var/www/wordpress/init.sh
WORKDIR /var/www/wordpress
ENTRYPOINT ["sh", "./init.sh"]