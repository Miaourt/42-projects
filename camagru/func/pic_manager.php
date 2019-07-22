<?php

include_once 'conf.php';
include_once FUNC_F.'ft_add_pic.php';
include_once FUNC_F.'ft_add_comment.php';
include_once FUNC_F.'ft_toggle_like.php';
include_once FUNC_F.'ft_del_pic.php';
include_once FUNC_F.'ft_effect.php';
include_once FUNC_F.'ft_normalize.php';

if ($_POST['action'] === "⬆️" && isset($_FILES['data']) && isset($_POST['effect'])) {
	switch (@exif_imagetype($_FILES['data']['tmp_name'])) {
		case 1:
			$data = imagecreatefromgif($_FILES['data']['tmp_name']);
			break;
		case 2:
			$data = imagecreatefromjpeg($_FILES['data']['tmp_name']);
			break;
		case 3:
			$data = imagecreatefrompng($_FILES['data']['tmp_name']);
			break;
		default:
			echo "Mauvais format d'image, seul GIF, JPEG et PNG.</br>Ou trop grosse.";
			$data = null;
			break;
	}
	if ($data) {
		if (is_numeric($_POST['effect']) && $_POST['effect'] > 0 && $_POST['effect'] < 10) {
			ft_add_pic(ft_effect(ft_normalize($data), $_POST['effect']));
			echo "Image créee avec succès !";
		} else {
			echo "Mauvais ID d'effet.";
		}
	}
	header("refresh:2;url=".SITE_ROOT_URL);
}

if ($_POST['action'] === "🗑️" && isset($_POST['id'])) {
	header("refresh:2;url=".SITE_ROOT_URL);
	echo ft_del_pic($_POST['id']);
}

if (($_POST['action'] === "⭐" || $_POST['action'] === "🌟" ) && isset($_POST['id']) && isset($_POST['page'])) {
	header("refresh:2;url=".SITE_ROOT_URL."/".$_POST['page']);
	echo ft_add_like($_POST['id']);
}

if ($_POST['action'] === "💬" && isset($_POST['content']) && isset($_POST['id']) && isset($_POST['page'])) {
	header("refresh:2;url=".SITE_ROOT_URL."/".$_POST['page']);
	echo ft_add_comment($_POST['id'], $_POST['content']);
}

?>
