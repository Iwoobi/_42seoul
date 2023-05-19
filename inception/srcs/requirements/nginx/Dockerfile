FROM	debian:buster

RUN 	apt-get -y update
RUN    	apt-get -y upgrade
RUN	apt-get install -y nginx
RUN	apt-get install -y openssl

RUN		openssl req -newkey rsa:4096 -days 365 -nodes -x509\
        -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Gun/CN=youhan"\
        -keyout /etc/ssl/private/youhan.key\
        -out /etc/ssl/certs/youhan.crt
RUN     chmod 777 /etc/ssl/certs/youhan.crt
RUN	chmod 777 /etc/ssl/private/youhan.key
EXPOSE	443
COPY	./conf/default.conf	/etc/nginx/conf.d/

ENTRYPOINT ["nginx", "-g", "daemon off;"]