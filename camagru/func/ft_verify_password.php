<?php

include_once FUNC_F.'ft_db.php';

function ft_verify_password($username, $password) {
	$db = ft_db();
	$query = $db->prepare("SELECT password FROM users WHERE username = :username;");
	if (!($query->execute(array('username' => trim(strtolower($username)))))) {
		$db = null;
		return false;
	}
	$result = $query->fetch(PDO::FETCH_ASSOC);
	$db = null;
	if (password_verify($password, $result['password']))
		return true;
	else
		return false;
}

?>
