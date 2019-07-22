<?php

include_once FUNC_F.'ft_db.php';
include_once FUNC_F.'ft_verify_password.php';
include_once FUNC_F.'ft_account_state.php';

function ft_validate_email($username, $password, $token) {
	if (ft_verify_password($username, $password)) {
		if (ft_account_state($_POST['username']) == 1) {
			if (ft_verify_validation_token($username, $token)) {
				$db = ft_db();
				$query = $db->prepare("UPDATE users SET account_state = 2, validation_token = -1 WHERE username = :username;");
				if (!($query->execute(array('username' => $username)))) {
					$db = null;
					return "Une erreur s'est produite.";
				}
				$db = null;
				return "Compte validé !<br/>Vous pouvez à présent vous connecter !";
			}
			return "Echec de la validation du compte, token incorrect";
		}
		return "Compte déjà validé !";
	}
	return "Echec de la validation du compte, nom d'utilisateur ou mot de passe incorrect";
}

?>
