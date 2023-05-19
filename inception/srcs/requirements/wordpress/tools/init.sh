sleep 10;
if  [ ! -f /var/www/wordpress/wp-config.php ]; then
	wp core download --locale=en_US --allow-root --force
	wp core config --allow-root \
	--dbname=$DB_NAME \
	--dbuser=$DB_USER \
	--dbpass=$DB_PASS \
	--dbhost=mariadb:3306


	wp core install --allow-root \
	--url=$DOMAIN_NAME \
 	--title='Inception' \
 	--admin_user=$WP_ADMIN \
	--admin_password=$WP_ADMINPASS \
 	--admin_email="cocoduddnd@naver.com" \
 	--path='/var/www/wordpress';

 	wp  user create --allow-root \
 	$WP_USER youhan2@student.42seoul.kr \
 	--user_pass=$WP_PASS --role=author
fi

php-fpm7.3 --nodaemonize