<?php

include_once FUNC_F.'ft_db.php';
include_once FUNC_F.'ft_islog.php';


function ft_add_pic($image) {
	$username = ft_islog();
	if ($username) {
		$db = ft_db();
		$date = date('Y/m/d');
		$imgname = uniqid("pic_");
		if (!file_exists(PICS_F.$date)) {
			mkdir(PICS_F.$date, 0755, true);
		}
		imagejpeg($image, PICS_F.$date.'/'.$imgname.'.jpg');
		$insert = $db->prepare("INSERT INTO pics (id_author, img_path) VALUES (:id_author, :img_path);");
		if (!($insert->execute(array('id_author' => ft_get_userid($username), 'img_path' => PICS_F.$date.'/'.$imgname.'.jpg' )))) {
			$db = null;
			return "Une erreur s'est produite.";
		}
		return "Image créée avec succès !";
	} else {
		return "Non connecté.";
	}
}

?>
