<?php

function ft_logout($token) {
	$db = ft_db();
	if (!$token == '') {
		$query = $db->prepare("SELECT token FROM users WHERE token = :token");
		if (!($query->execute(array('token' => $token)))) {
			$db = null;
			return "Une erreur s'est produite.";
		}
		$result = $query->fetch(PDO::FETCH_ASSOC);
		if ($result && $result['token'] != -1) {
			$query = $db->prepare("UPDATE users SET token = '-1' WHERE token = :token;");
			if (!($query->execute(array('token' => $token)))) {
				$db = null;
				return "Une erreur s'est produite.";
			}
			ft_cook('set', TOKEN_PREFIX.'token', '', -1);
			return ("Déconnecté !");
		}
	}
	return "Mauvais token";
}

?>
