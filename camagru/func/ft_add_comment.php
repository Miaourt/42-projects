<?php

include_once FUNC_F.'ft_db.php';
include_once FUNC_F.'ft_islog.php';
include_once FUNC_F.'ft_get_userid.php';
include_once FUNC_F.'ft_get_username.php';
include_once FUNC_F.'ft_send_comm_email.php';

function ft_add_comment($id, $content) {
	$username = ft_islog();
	if ($username) {
		$db = ft_db();
		$query = $db->prepare("SELECT id, id_author FROM pics WHERE :picsid = id");
		if (!($query->execute(array('picsid' => $id)))) {
			$db = null;
			return "Une erreur s'est produite.";
		}
		$result = $query->fetch(PDO::FETCH_ASSOC);
		if (!$result) {
			$db = null;
			return "L'image n'existe pas.";
		}
		if (strlen($content) > 512) {
			$db = null;
			return "Commentaire trop long. Pas plus de 512 charactères.";
		}
		$addition = $db->prepare("INSERT INTO comments (id_author, id_pics, content) VALUES (:id_author, :picsid, :content);");
		if (!($addition->execute(array('id_author' => ft_get_userid($username),'picsid' => $id, 'content' => $content)))) {
			$db = null;
			return "Une erreur s'est produite.";
		}
		if ($result['id_author'] != ft_get_userid($username)) {
			ft_send_comm_email(ft_get_username($result['id_author']), $id, $content, $username);
		}
		return "Commentaire ajouté avec succès !";
	} else {
		return "Non connecté.";
	}
}

?>
