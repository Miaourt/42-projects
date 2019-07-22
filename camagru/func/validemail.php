<?php

include_once 'conf.php';
include_once FUNC_F.'ft_send_validation_mail.php';
include_once FUNC_F.'ft_verify_validation_token.php';
include_once FUNC_F.'ft_verify_password.php';
include_once FUNC_F.'ft_account_state.php';
include_once FUNC_F.'ft_validate_email.php';

if (isset($_POST['action']) && $_POST['action'] === "Confirmer" &&
		isset($_POST['username']) && !$_POST['username'] == '' &&
		isset($_POST['password']) && !$_POST['password'] == '' &&
		isset($_POST['token']) && !$_POST['token'] == '') // plutôt explicite
		{
	header("refresh:2;url=/");
	echo ft_validate_email($_POST['username'], $_POST['password'], $_POST['token']);
}
else if (isset($_POST['action']) && $_POST['action'] === "Renvoyer l'email d'inscription" &&
		isset($_POST['username']) && !$_POST['username'] == '' &&
		isset($_POST['password']) && !$_POST['password'] == '') // plutôt explicite
		{
	if (ft_verify_password($_POST['username'], $_POST['password'])) {
		if (ft_account_state($_POST['username'] == 1)) {
			if (ft_send_validation_mail($_POST['username'])) {
				$out = "Nouvel email envoyé !<br/>Vérifiez votre boîte mail afin de valider votre compte !";
			}
			else {
				$out = "Erreur lors de l'envois de l'email de validation, veuillez re-essayer";
			}
		}
		else {
			$out = "Compte déjà validé !";
		}
	}
	else {
		$out = "Mot de passe ou nom d'utilisateur incorrect";
	}
	header("refresh:2;url=".SITE_ROOT_URL."/?validemail");
	include(VIEW_F.'head.php');
	echo $out;
}
else {
	$out = "Formulaire incorrect. 🙄";
	header("refresh:2;url=".SITE_ROOT_URL."/?validemail");
	echo $out;
}

?>
