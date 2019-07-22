<?php
include_once FUNC_F.'ft_db.php';
include_once FUNC_F.'ft_islog.php';


function ft_get_pic($id) {
	$db = ft_db();
	$query = $db->prepare("SELECT pics.id, pics.id_author, pics.img_path, users.username FROM pics INNER JOIN users ON users.id = pics.id_author WHERE :id = pics.id");
	if (($query->execute(array('id' => $id)))) {
		$result = $query->fetch(PDO::FETCH_ASSOC);
		if ($result) {
				return SITE_ROOT_URL."/".$result["img_path"];
		} else {
			return "L'image n'existe pas";
		}
	}
	return "une erreur s'est produite";
}
?>
