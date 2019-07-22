<?php

include_once FUNC_F.'ft_db.php';
include_once FUNC_F.'ft_islog.php';
include_once FUNC_F.'ft_get_userid.php';


function ft_add_like($id) {
	$username = ft_islog();
	if ($username) {
		$db = ft_db();
		$query = $db->prepare("SELECT id FROM pics WHERE :picsid = id");
		if (!($query->execute(array('picsid' => $id)))) {
			$db = null;
			return "Une erreur s'est produite.";
		}
		$result = $query->fetch(PDO::FETCH_ASSOC);
		if (!$result) {
			$db = null;
			return "L'image n'existe pas.";
		}
		$query = $db->prepare("SELECT id FROM pics WHERE :picsid = id AND :userid = id_author");
		if (!($query->execute(array('picsid' => $id, 'userid' => ft_get_userid($username))))) {
			$db = null;
			return "Une erreur s'est produite.";
		}
		$result = $query->fetch(PDO::FETCH_ASSOC);
		if ($result) {
			$db = null;
			return "Vous ne pouvez pas liker vos propres images !";
		}
		$query = $db->prepare("SELECT id FROM likes WHERE :picsid = id_pics AND :userid = id_author");
		if (!($query->execute(array('picsid' => $id, 'userid' => ft_get_userid($username))))) {
			$db = null;
			return "Une erreur s'est produite.";
		}
		$result = $query->fetch(PDO::FETCH_ASSOC);
		if ($result) {
			$deletion = $db->prepare("DELETE FROM likes WHERE :picsid = id_pics AND :userid = id_author");
			if (!($deletion->execute(array('picsid' => $id, 'userid' => ft_get_userid($username))))) {
				$db = null;
				return "Une erreur s'est produite.";
			}
			return "Like supprimée avec succès !";
		}
		$addition = $db->prepare("INSERT INTO likes (id_author, id_pics) VALUES (:id_author, :picsid);");
		if (!($addition->execute(array('id_author' => ft_get_userid($username),'picsid' => $id)))) {
			$db = null;
			return "Une erreur s'est produite.";
		}
		return "Like ajouté avec succès !";
	} else {
		return "Non connecté.";
	}
}

?>
