<?php

include_once FUNC_F.'ft_db.php';

function ft_account_state($username) {
	$db = ft_db();
	$query = $db->prepare("SELECT account_state FROM users WHERE username = :username;");
	if (!($query->execute(array('username' => trim(strtolower($username)))))) {
		$db = null;
		return 0;
	}
	$result = $query->fetch(PDO::FETCH_ASSOC);
	$db = null;
	return $result['account_state'];
}

?>
