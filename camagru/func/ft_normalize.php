<?php

include_once FUNC_F.'ft_db.php';
include_once FUNC_F.'ft_islog.php';

function ft_normalize($image) {
	if ($image) {
		$max = 960;
		$ix = imagesx($image);
		$iy = imagesy($image);
		$imax = max($ix, $iy);
		$return = imagescale(imagescale($image, $max), $ix * $max / $imax, $iy * $max / $imax);
		imagedestroy($image);
		return ($return);
	}
}

?>
