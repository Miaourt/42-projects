<?php

include_once FUNC_F.'ft_db.php';

function ft_verify_email($username, $email) {
	$db = ft_db();
	$query = $db->prepare("SELECT email FROM users WHERE username = :username;");
	if (!($query->execute(array('username' => $username)))) {
		$db = null;
		return false;
	}
	$result = $query->fetch(PDO::FETCH_ASSOC);
	$db = null;
	if ($result['email'] == $email) {
		return true;
	}
	return false;
}

?>
