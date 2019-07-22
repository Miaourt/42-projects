<?php

include_once FUNC_F.'ft_db.php';

function ft_reset_password($token, $password) {
	if (!ctype_cntrl($password)) {
		$db = ft_db();
		$query = $db->prepare("SELECT reset_token FROM users WHERE reset_token = :token");
		if (!($query->execute(array('token' => $token)))) {
			$db = null;
			return false;
		}
		$result = $query->fetch(PDO::FETCH_ASSOC);
		if (!$result) {
			$db = null;
			return false;
		}
		$insert = $db->prepare("UPDATE users SET password = :password, reset_token = -1 WHERE reset_token = :token;");
		if ($insert->execute(array('password' => password_hash($password, PASSWORD_DEFAULT), 'token' => $token))) {
			$db = null;
			return true;
		}
		$db = null;
	}
	return false;
}

?>
