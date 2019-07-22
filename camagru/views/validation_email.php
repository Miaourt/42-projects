<?php
if (isset($_GET['token'])) {
	$token = $_GET['token'];
}
else {
	$token = "";
}
?>
<div class="session">
	<div>
		<form action="<?php echo SITE_ROOT_URL ?>/?valid" method="POST">
			<input type="text" name='username' placeholder="Nom d'utilisateur"/></br>
			<input type="password" name='password' placeholder="Mot de passe"/></br>
			<input type="text" name="token" placeholder="Token" value="<?php echo $token ?>"/></br>
			<input type="submit" name='action' value="Confirmer" class="action"></br>
			<input type="submit" name='action' value="Renvoyer l'email d'inscription" class="action"></br>
		</form>
		<a href="<?php echo SITE_ROOT_URL ?>/?resetpass">Mot de passe oublié ?</a></br>
		<a href="<?php echo SITE_ROOT_URL ?>">Se connecter ?</a></br>
		<a href="<?php echo SITE_ROOT_URL ?>">S'inscrire ?</a>
	</div>
</div>
