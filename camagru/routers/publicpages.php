<?php include_once FUNC_F.'ft_islog.php' ?>

<html>
	<?php include(VIEW_F.'head.php') ?>
	<body>
		<?php include(VIEW_F.'header.php') ?>
		<div class="content">
			<?php
				if (isset($_GET['register'])) {
					include(VIEW_F.'register.php');
				} elseif (isset($_GET['resetpass'])) {
					include(VIEW_F.'reset_pass.php');
				} elseif (isset($_GET['resetpass_pwd'])) {
					include(VIEW_F.'reset_pass_pwdform.php');
				} elseif (isset($_GET['validemail'])) {
					include(VIEW_F.'validation_email.php');
				} elseif (isset($_GET['gallery'])) {
					include(VIEW_F.'gallery.php');
				} elseif (isset($_GET['pic'])) {
					include(VIEW_F.'pic.php');
				} elseif (ft_islog()) {
					include(VIEW_F.'dashboard.php');
				} else {
					include(VIEW_F.'login.php');
				}
			?>
		</div>
	</body>
</html>
