# ----------------------------------
# --------- Image creation ---------
# ----------------------------------

# Copyright {2020} {Witold Guillaume}

# Install os
FROM debian:stretch

# Install packages: apache2, php, php-pear, php-mysql
RUN apt-get update && apt-get install -y apache2
RUN apt-get install -y php
RUN apt-get install -y php-pear
RUN apt-get install -y php-mysql

# Run a shell command
RUN rm /var/www/html/index.html

# Copy a file in the image
COPY ./index.php /var/www/html/index.php

#Make a port visible
EXPOSE 80

# Execute
CMD ["/usr/sbin/apachectl", "-D", "FOREGROUND"]

# ----------------------------------
# ------------ Commands ------------
# ----------------------------------

# Pour créer l'image
# docker build . -t http

docker-compose build #construction
docker-compose up #montage
