<?php

include_once FUNC_F.'ft_db.php';
include_once FUNC_F.'ft_islog.php';
include_once FUNC_F.'ft_get_userid.php';


function ft_is_like($id) {
	$username = ft_islog();
	if ($username) {
		$db = ft_db();
		$query = $db->prepare("SELECT id FROM likes WHERE :picsid = id_pics AND :userid = id_author");
		if (!($query->execute(array('picsid' => $id, 'userid' => ft_get_userid($username))))) {
			$db = null;
			return null;
		}
		$result = $query->fetch(PDO::FETCH_ASSOC);
		if ($result) {
			$db = null;
			return true;
		}
		return false;
	} else {
		return null;
	}
}

?>
