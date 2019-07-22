<?php

include_once FUNC_F.'ft_db.php';
include_once FUNC_F.'ft_random_string.php';
include_once FUNC_F.'ft_send_validation_mail.php';

function ft_createuser($username, $password, $email) {
	$db = ft_db();
	$query = $db->prepare("SELECT username FROM users WHERE username = :username");
	if (!($query->execute(array('username' => $username)))) {
		$db = null;
		return "Une erreur s'est produite.";
	}
	$result = $query->fetch(PDO::FETCH_ASSOC);
	if ($result) {
		$db = null;
		return "Nom d'utilisateur déjà utilisé";
	}
	if (strlen($password) < 8) {
		$db = null;
		return "Mot de passe trop court, 8 charactères minimum";
	}
	$handle = fopen(FUNC_F.'dico.txt', 'r');
	$buffer = "mot de passe";
	while (!feof($handle) && ($buffer != $password)) {
		$buffer = trim(fgets($handle));
	}
	if ($buffer == $password) {
		$db = null;
		return "Mot de passe dans le dictionaire.";
	}
	fclose($handle);
	if (ctype_alnum(trim($username)) && !ctype_cntrl($password) && filter_var(trim($email), FILTER_VALIDATE_EMAIL)) {
		$insert = $db->prepare("INSERT INTO users (username, password, email, validation_token) VALUES (:username, :password, :email, :validation_token);");
		if (!($insert->execute(array('username' => trim(strtolower($username)), 'password' => password_hash($password, PASSWORD_DEFAULT), 'email' => trim($email), 'validation_token' => ft_random_string(128))))) {
			$db = null;
			return "Une erreur s'est produite.";
		}
		$db = null;
		if (ft_send_validation_mail($username)) {
			return "Utilisateur créé !<br/>Vérifiez votre boîte mail afin de valider votre compte !";
		}
		return "Erreur lors de l'envois de l'email de validation, veuillez re-tenter l'inscription";
	}

	else {
		$db = null;
		return "Nom d'utilisateur non-alphanumérique, mot de passe contenant de caractères invalides ou email incorrecte";
	}
}

?>
