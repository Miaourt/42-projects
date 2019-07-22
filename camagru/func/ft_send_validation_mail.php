<?php

include_once 'conf.php';
include_once FUNC_F.'ft_db.php';

function ft_send_validation_mail($username) {
	$db = ft_db();
	$query = $db->prepare("SELECT validation_token, email FROM users WHERE username = :username");
	if (!($query->execute(array('username' => $username)))) {
		$db = null;
		return false;
	}
	$result = $query->fetch(PDO::FETCH_ASSOC);
	$db = null;

	$subject = "Inscription sur ".SITE_NAME." | Validation de l'adresse email";
	$txt = "Quelqu'un s'est inscrit sur ".SITE_NAME." avec l'adresse : ".$result['email']."."."\r\n".
	"Si c'est vous, veuillez valider votre compte en cliquant sur ce lien : "."\r\n".SITE_ROOT_URL."/?validemail&token=".$result['validation_token']."\r\n".
	"Sinon, ignorez-le."."\r\n".
	"Si le lien ne fonctionne pas, utilisez ce token : "."\r\n".$result['validation_token']."\r\n".
	"Merci !"."\r\n".
	"L'équipe de ".SITE_NAME;
	$headers = "From: ".SITE_EMAIL;

	if (mail($result['email'],$subject,$txt,$headers)) {
		return true;
	}
	return false;
}

?>
