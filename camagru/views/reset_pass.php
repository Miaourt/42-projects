<div class="session">
	<div></br>
		<form action="<?php echo SITE_ROOT_URL ?>/?reset" method="POST">
			<input type="text" name='username' placeholder="Nom d'utilisateur"/></br>
			<input type="email" name='email' placeholder="Adresse email"/></br>
			<input type="submit" name='action' value="Récupérer le compte" class="action"></br>
		</form>
		<a href="<?php echo SITE_ROOT_URL ?>/?validemail">Email non validé ?</a></br>
		<a href="<?php echo SITE_ROOT_URL ?>">Se connecter ?</a></br>
		<a href="<?php echo SITE_ROOT_URL ?>">S'inscrire ?</a>
	</div>
</div>
