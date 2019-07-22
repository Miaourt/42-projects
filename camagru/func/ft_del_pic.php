<?php

include_once FUNC_F.'ft_db.php';
include_once FUNC_F.'ft_islog.php';
include_once FUNC_F.'ft_get_userid.php';


function ft_del_pic($id) {
	$username = ft_islog();
	if ($username) {
		$db = ft_db();
		$query = $db->prepare("SELECT id_author, img_path FROM pics WHERE :picsid = id");
		if (!($query->execute(array('picsid' => $id)))) {
			$db = null;
			return "Une erreur s'est produite.";
		}
		$result = $query->fetch(PDO::FETCH_ASSOC);
		unlink ($result['img_path']);
		if (!($result['id_author'] == ft_get_userid($username))) {
			$db = null;
			return "Vous n'êtes pas l'auteur de l'image.";
		}
		$deletion = $db->prepare("DELETE FROM pics WHERE :picsid = id");
		if (!($deletion->execute(array('picsid' => $id,)))) {
			$db = null;
			return "Une erreur s'est produite.";
		}
		$deletion = $db->prepare("DELETE FROM likes WHERE :picsid = id_pics");
		if (!($deletion->execute(array('picsid' => $id,)))) {
			$db = null;
			return "Une erreur s'est produite.";
		}
		$deletion = $db->prepare("DELETE FROM comments WHERE :picsid = id_pics");
		if (!($deletion->execute(array('picsid' => $id,)))) {
			$db = null;
			return "Une erreur s'est produite.";
		}
		return "Image supprimée avec succès !";
	} else {
		return "Non connecté.";
	}
}

?>
