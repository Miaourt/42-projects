<?php

include_once ('conf.php');

function ft_db()
{
	try
	{
		$conn = new PDO(DB_DRIVER.":host=".DB_HOST.";dbname=".DB_NAME.";port=".DB_PORT, DB_USER, DB_PASSWORD);
		$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); // set the PDO error mode to exception
		return $conn;
	}
	catch(PDOException $e)
	{
		//echo $sql . "<br>" . $e->getMessage();
		return false;
	}

}

?>
