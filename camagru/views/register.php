<div class="session">
	<div>
		<form action="<?php echo SITE_ROOT_URL ?>/?session" method="POST">
			<input type="text" name='username' placeholder="Nom d'utilisateur" pattern="[a-zA-Z0-9]{2,20}"
				title="Entre 2 et 20 caractères alphanumériques"></br>
			<input type="password" name='password' placeholder="Mot de passe" pattern="[a-zA-Z0-9]{8,99}"
				title="Entre 8 et 99 caractères alphanumériques"/></br>
			<input type="email" name='email' placeholder="Adresse email"/></br>
			<input type="submit" name='action' value="Inscription" class="action"></br>
		</form>
		<a href="<?php echo SITE_ROOT_URL ?>">Déjà inscrit ?</a></br>
		<a href="<?php echo SITE_ROOT_URL ?>?resetpass">Mot de passe oublié ?</a></br>
		<a href="<?php echo SITE_ROOT_URL ?>?validemail">Email non validé ?</a>
	</div>
</div>
