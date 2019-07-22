<?php

include_once 'conf.php';
include_once FUNC_F.'ft_createuser.php';
include_once FUNC_F.'ft_login.php';
include_once FUNC_F.'ft_logout.php';
include_once FUNC_F.'ft_islog.php';

if (isset($_POST['action']) && $_POST['action'] === "Inscription" && !$_POST['username'] == '' && !$_POST['password'] == '' && !$_POST['email'] == '') // plutôt explicite
{
		$out = ft_createuser($_POST['username'], $_POST['password'], $_POST['email']);
}
else if (isset($_POST['action']) && $_POST['action'] === "Connexion" && !$_POST['username'] == '' && !$_POST['password'] == '') // plutôt explicite aussi
{
		$out = ft_login($_POST['username'], $_POST['password']);
}
else if (isset($_GET['logout'])) // si on envois un GET avec "logout", on déconnecte la session
{
	$out = ft_logout($_COOKIE[TOKEN_PREFIX.'token']);
}
else if (isset($_COOKIE[TOKEN_PREFIX.'token']) && ft_islog($_COOKIE[TOKEN_PREFIX.'token'])) { // redirection immediate si il est déjà connecté
	$out = "Déjà connecté.";
} else {
	$out = "Pékwah t'es là ? 🤔";
}
// Redirection après 2 secondes , et j'envois $out qui est le message de retour des fonctions ci-dessus.
header("refresh:2;url=".SITE_ROOT_URL."/");
echo $out;

?>
