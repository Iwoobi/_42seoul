service mysql start;

if  [ ! -d "/var/lib/mysql/${DB_NAME}"  ]; then

	mysql -e "CREATE DATABASE IF NOT EXISTS ${DB_NAME};"
	mysql -e "CREATE USER '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASS}';"
	mysql -e "GRANT ALL PRIVILEGES ON *.* TO '${DB_USER}'@'%';"
	mysql -e "FLUSH PRIVILEGES;"
	sleep 5
	mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOTPASS}';"
fi

mysqladmin -u root -p${DB_ROOTPASS} shutdown	





exec mysqld_safe