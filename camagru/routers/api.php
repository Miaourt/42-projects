<?php

if (isset($_GET['pics'])) {
	include(FUNC_F.'pic_manager.php');
}
elseif (isset($_GET['session'])) {
	include(FUNC_F.'session.php');
}
elseif (isset($_GET['reset'])) {
	include(FUNC_F.'resetpass.php');
}
elseif (isset($_GET['reset_pwd'])) {
	include(FUNC_F.'resetpass.php');
}
elseif (isset($_GET['valid'])) {
	include(FUNC_F.'validemail.php');
}

include(VIEW_F.'redirhead.php');
echo "<br/><span>Redirection dans ~2 secondes</span>";

?>
