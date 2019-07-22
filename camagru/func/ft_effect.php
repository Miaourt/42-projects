<?php

include_once FUNC_F.'ft_db.php';
include_once FUNC_F.'ft_islog.php';

function ft_effect($image, $id) {
	switch ($id) {
		case 1:
			$filter = imagecreatefrompng(FILTER_F."1.png"); //chat
			if ($image) {
				if (imagecopy($image, $filter, 0, imagesy($image) - 500, 0, 0, imagesx($filter), imagesy($filter))) {
					return ($image);
				}
			}
		break;
		case 2:
			$filter = imagecreatefrompng(FILTER_F."2.png"); //coeur
			if ($image) {
				if (imagecopy($image, $filter, imagesx($image) / 3, imagesy($image) / 3, 0, 0, imagesx($filter), imagesy($filter))) {
					if (imagefilter ($image, IMG_FILTER_COLORIZE, 247, 103, 144, 50)) {
						return ($image);
					}
				}
			}
		break;
		case 3:
			if ($image) {
				if (imagefilter ($image, IMG_FILTER_EDGEDETECT)) { //detection de bord
					return ($image);
				}
			}
		break;
		case 4:
			if ($image) {
				if (imagefilter ($image, IMG_FILTER_EMBOSS)) { //embosser
					return ($image);
				}
			}
		break;
		case 5:
			if ($image) {
				if (imagefilter ($image, IMG_FILTER_NEGATE)) { //negatif
					return ($image);
				}
			}
		break;
		case 6:
			if ($image) {
				if (imagefilter ($image, IMG_FILTER_PIXELATE, 20, true)) { // pixelisation
					return ($image);
				}
			}
		break;
		case 7:
			$filter = imagecreatefrompng(FILTER_F."1.png"); //chat
			if ($image) {
				if (imagecopy($image, $filter, 0, imagesy($image) - 500, 0, 0, imagesx($filter), imagesy($filter))) {
					return ($image);
				}
			}
		break;

		default:
			echo "ID invalid";
			return ($image);
			break;
	}
}

?>
