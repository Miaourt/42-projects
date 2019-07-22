<?php

include_once FUNC_F.'ft_db.php';

function ft_islog() {
	if (isset($_COOKIE[TOKEN_PREFIX.'token'])) {
		$token = $_COOKIE[TOKEN_PREFIX.'token'];
		$db = ft_db();
		$query = $db->prepare("SELECT token, username FROM users WHERE token = :token");
		if (!($query->execute(array('token' => $token)))) {
			$db = null;
			return false;
		}
		$result = $query->fetch(PDO::FETCH_ASSOC);
		$db = null;
		if ($result && $result['token'] != -1)
			return ($result['username']);
		return(false);
	}
}

?>
