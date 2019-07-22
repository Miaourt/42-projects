<?php

define("DB_DRIVER", "mysql");
define("DB_NAME", "tbo");
define("DB_HOST", "localhost");
define("DB_PORT", "3306");
define("DB_USER", "root");
define("DB_PASSWORD", "admin");

//pour faire plaisir mais c'est pas beau

$DB_USER = DB_USER;
$DB_DSN = DB_DRIVER.":host=".DB_HOST;
$DB_PASSWORD = DB_PASSWORD;

//\
?>
