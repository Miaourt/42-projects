<?php

function ft_cook($action, $name, $value, $duration) {
	if (isset($action) && isset($name))
	{
		if ($action == "set")
		{
			if (isset($value))
			{
				setcookie($name, $value, time() + $duration);
			}
		}
		elseif ($action == "get")
		{
			if (isset($_COOKIE[$_GET["name"]]))
			{
				echo $_COOKIE[$_GET["name"]]."\n";
			}
		}
		elseif ($action == "del")
		{
			setcookie($name, "", 1);
		}
	}
}

?>
