<?php

include_once FUNC_F.'ft_db.php';

function ft_get_userid($username) {
	$db = ft_db();
	$query = $db->prepare("SELECT id FROM users WHERE username = :username");
	if ($query->execute(array('username' => $username))) {
		$result = $query->fetch(PDO::FETCH_ASSOC);
		$db = null;
		return $result['id'];
	}
	$db = null;
	return false;
}

?>
