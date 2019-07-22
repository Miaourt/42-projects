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
		<form action="<?php echo SITE_ROOT_URL ?>/?reset" method="POST">
			<input type="password" name='password' placeholder="Nouveau mot de passe"/>
			<input type="text" name="token" placeholder="Token" value="<?php echo $token ?>"/>
			<input type="submit" name='action' value="Utiliser ce nouveau mot de passe">
		</form>
	</div>
</div>
