<?php

include_once FUNC_F.'ft_db.php';

function ft_verify_validation_token($username, $token) {
	$db = ft_db();
	$query = $db->prepare("SELECT validation_token FROM users WHERE username = :username;");
	if (!($query->execute(array('username' => $username)))) {
		$db = null;
		return false;
	}
	$result = $query->fetch(PDO::FETCH_ASSOC);
	$db = null;
	if ($result['validation_token'] == $token) {
		return true;
	}
	return false;
}

?>
