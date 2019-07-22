<?php

include_once 'conf.php';
include_once FUNC_F.'ft_db.php';

function ft_send_reset_mail($username) {
	$db = ft_db();
	$query = $db->prepare("SELECT reset_token, email FROM users WHERE username = :username");
	if (!($query->execute(array('username' => $username)))) {
		$db = null;
		return false;
	}
	$result = $query->fetch(PDO::FETCH_ASSOC);
	$db = null;

	$subject = "Récupération du compe sur ".SITE_NAME."";
	$txt = "Quelqu'un à demandé à récupéré le mot de passe du compte ".$username." sur ".SITE_NAME."\r\n".
	"Si c'est vous, veuillez cliquer sur ce lien :"."\r\n".SITE_ROOT_URL."/?resetpass_pwd&token=".$result['reset_token']."\r\n".
	"Sinon, ignorez-le."."\r\n".
	"Si le lien ne fonctionne pas, utilisez ce token :"."\r\n".$result['reset_token']."\r\n".
	"Merci !"."\r\n".
	"L'équipe de ".SITE_NAME;
	$headers = "From: ".SITE_EMAIL;

	if (mail($result['email'],$subject,$txt,$headers)) {
		return true;
	}
	return false;
}

?>
