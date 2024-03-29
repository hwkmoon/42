# Config ssl
mkdir /etc/nginx/ssl
chmod 700 /etc/nginx/ssl
openssl req -x509 -sha256 -nodes -days 365 -newkey rsa:4096 -keyout /etc/nginx/ssl/nginx-selfsigned.key -out /etc/nginx/ssl/nginx-selfsigned.crt -subj "/C=FR/ST=Paris/L=Franconville/O=42/OU=hkortbi/CN=localhost"


# Config nginx and autoindex
if [ "$AUTOINDEX" = "off" ];
    then mv default_off etc/nginx/sites-enabled/
    else mv default etc/nginx/sites-enabled/
fi
chown -R www-data /var/www/*
chmod -R 755 /var/www/*

# Config mysql
service mysql start
echo "create database wordpress default character set utf8 collate utf8_unicode_ci;" | mysql -u root
echo "create user 'couscous'@'localhost' identified by 'merguez22';" | mysql -u root
echo "grant all privileges on wordpress.* TO 'couscous'@'localhost'" | mysql -u root
echo "flush privileges;" | mysql -u root

# Config phpmyadmin new user
service php7.3-fpm start
echo "grant all on *.* to 'hkortbi'@'localhost' IDENTIFIED BY 'lemotdepasse'" | mysql -u root
echo "flush privileges;" | mysql -u root

# Launch
service nginx start
nginx -t
service nginx restart
service mysql restart
service php7.3-fpm restart
sleep infinity