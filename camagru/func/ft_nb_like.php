<?php

include_once FUNC_F.'ft_db.php';
include_once FUNC_F.'ft_get_userid.php';


function ft_nb_like($id) {
	$db = ft_db();
	$query = $db->prepare("SELECT COUNT(*) AS likes FROM likes WHERE :picsid = id_pics");
	if (!($query->execute(array('picsid' => $id)))) {
		$db = null;
		return 0;
	}
	$result = $query->fetch(PDO::FETCH_ASSOC);
	return $result["likes"];
}

?>
