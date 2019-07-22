<?php

include_once 'conf.php';
include_once FUNC_F.'ft_send_reset_mail.php';
include_once FUNC_F.'ft_verify_email.php';
include_once FUNC_F.'ft_reset_password.php';
include_once FUNC_F.'ft_create_reset_token.php';

if (isset($_POST['action']) && $_POST['action'] === "Récupérer le compte" &&
		isset($_POST['username']) && !$_POST['username'] == '' &&
		isset($_POST['email']) && !$_POST['email'] == '') // plutôt explicite
{
	if (ft_verify_email($_POST['username'],$_POST['email'])) {
		if (ft_create_reset_token($_POST['username'])) {
			if (ft_send_reset_mail($_POST['username'])) {
				$out = "Email de récupération envoyé !<br/>Vérifiez votre boîte mail afin de récupérer votre compte !";
			}
			else
				$out = "Erreur lors de l'envois de l'email de récupération, veuillez re-essayer";
		}
		else {
			$out = "Nom d'utilisateur ou adresse email incorrecte.";
		}
	}
	else {
		$out = "Nom d'utilisateur ou adresse email incorrecte.";
	}
	header("refresh:2;url=".SITE_ROOT_URL."/?resetpass");
	echo $out;
}
else if (isset($_POST['action']) && $_POST['action'] === "Utiliser ce nouveau mot de passe" &&
		isset($_POST['password']) && !$_POST['password'] == '' &&
		isset($_POST['token']) && !$_POST['token'] == '')
{
	if (!ctype_cntrl($_POST['password']) && strlen($_POST['password']) > 8) {
		if (ft_reset_password($_POST['token'], $_POST['password'])) {
			$out = "Changement de mot de passe effectué !<br/>Vous pouvez dorénavant vous connecter avec ce dernier.";
		}
		else {
			$out = "Token invalide.";
		}
	}
	else {
		$out = "Mot de passe incorrecte.";
	}
	header("refresh:2;url=".SITE_ROOT_URL."/?resetpass");
	echo $out;
}
else if (isset($_GET['token'])) {
	$token = $_GET['token'];
	include VIEW_F.'reset_pass_pwdform.php';
}
else {
	echo "game over";
}

?>
