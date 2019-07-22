<?php

include_once FUNC_F.'ft_db.php';
include_once FUNC_F.'ft_random_string.php';

function ft_create_reset_token($username) {
	$db = ft_db();
	$insert = $db->prepare("UPDATE users SET reset_token = :reset_token WHERE username = :username;");
	if ($insert->execute(array('reset_token' => ft_random_string(128), 'username' => $username))) {
		$db = null;
		return true;
	}
	$db = null;
	return false;
}

?>
