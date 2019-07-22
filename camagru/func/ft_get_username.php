<?php

include_once FUNC_F.'ft_db.php';

function ft_get_username($id) {
	$db = ft_db();
	$query = $db->prepare("SELECT username FROM users WHERE id = :id");
	if ($query->execute(array('id' => $id))) {
		$result = $query->fetch(PDO::FETCH_ASSOC);
		$db = null;
		return $result['username'];
	}
	$db = null;
	return false;
}

?>
