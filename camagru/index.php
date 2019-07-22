<?php

session_start();
include_once 'conf.php';

if (file_exists('config/.installed')) {
	if (isset($_GET['pics']) ||
		isset($_GET['session']) ||
		isset($_GET['reset']) ||
		isset($_GET['reset_pwd']) ||
		isset($_GET['valid'])) {
			include(ROUTE_F.'api.php');
	} else {
		include (ROUTE_F.'publicpages.php');
	}
} else {
	header('Location: config/setup.php');  
}
?>
