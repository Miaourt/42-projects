<?php

include_once 'conf.php';
include_once FUNC_F.'ft_db.php';

function ft_send_comm_email($username, $id, $comm, $author) {
	$db = ft_db();
	$query = $db->prepare("SELECT email FROM users WHERE username = :username");
	if (!($query->execute(array('username' => $username)))) {
		$db = null;
		return false;
	}
	$result = $query->fetch(PDO::FETCH_ASSOC);
	$db = null;

	$subject = "Nouveau commentaire sur ".SITE_NAME."";
	$txt = "Bonjour ".$username.", il y a un nouveau commentaire sur votre image : "."\r\n"."\r\n".
	$author." a écrit :"."\r\n\"".$comm."\"\r\n"."\r\n".
	"Pour voir ce commentaire et y répondre, cliquez-ici : ".SITE_ROOT_URL."/?pic=".$id."\r\n";
	$headers = "From: ".SITE_EMAIL;

	if (mail($result['email'],$subject,$txt,$headers)) {
		return true;
	}
	return false;
}

?>
