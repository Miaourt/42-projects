<header>
	<div class="header-content">
		<a href="<?php echo SITE_ROOT_URL ?>" class="logo"><?php echo SITE_NAME ?></a>
		<?php if (ft_islog()): ?>
		<a href="<?php echo SITE_ROOT_URL ?>/?session&logout" class="logout" alt="Déconnexion" title="Déconnexion">❌</a>
		<a href="<?php echo SITE_ROOT_URL ?>" class="dashboard" alt="Éditeur" title="Éditeur">📷</a>
	<?php else: ?>
		<a href="<?php echo SITE_ROOT_URL ?>" class="logout" alt="Déconnexion" title="Déconnexion">👤</a>
	<?php endif;?>
		<a href="<?php echo SITE_ROOT_URL ?>?gallery" class="gallery" alt="Gallerie" title="Gallerie">🖼️</a>
	</div>
</header>
