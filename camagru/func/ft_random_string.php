<?php

function ft_random_string($size) {
	if ($size > 1)
		$size = $size / 2;
	else
		return 0;
	return (bin2hex(random_bytes($size)));
}

?>
