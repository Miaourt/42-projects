<?php

include_once FUNC_F.'ft_db.php';
include_once FUNC_F.'ft_random_string.php';
include_once FUNC_F.'ft_verify_password.php';
include_once FUNC_F.'ft_account_state.php';
include_once FUNC_F.'ft_cook.php';

function ft_login($username, $password) {
	if (ctype_alnum(trim($username)) && !ctype_cntrl($password)) {
		if (ft_verify_password($username, $password)) {
			if (($account_state = ft_account_state($username)) == 2) {
				$db = ft_db();
				$new_token = ft_random_string(128);
				$query = $db->prepare("UPDATE users SET token = :token WHERE username = :username;");
				if (!($query->execute(array('token' => $new_token, 'username' => $username)))) {
					$db = null;
					return "Une erreur s'est produite.";
				}
				ft_cook('set', TOKEN_PREFIX.'token', $new_token, 3600);
				return "Connecté en tant que <i>".$username."</i> !";
			}
			else if ($account_state == 1) {
				return "Email non-validé !<br/>Vérifiez votre boîte mail !";
			}
			else if ($account_state == 3) {
				return "Ce compte a été banni !";
			}
		}
		else {
			return "Nom d'utilisateur ou mot de passe incorrecte";
		}
	}
	else {
		return "Nom d'utilisateur non-alphanumérique ou mot de passe contenant de caractères invalides";
	}
}

?>
