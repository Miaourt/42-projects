<?php

include ('database.php');

if (!file_exists('.installed') || isset($_GET['force'])) { // With the power of friendship, you can pass trought the .installed
	if (file_exists('rawdb.sql')) {
		try {
			$conn = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD); // Creation of the cute PDO object
			$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); // set the PDO error mode to exception
			$sql = "CREATE DATABASE IF NOT EXISTS ".DB_NAME."; USE ".DB_NAME.";"; // creation and use of a new db
			$conn->exec($sql.file_get_contents("rawdb.sql")); // We use a dumped DB to init our database
			touch('.installed');
			echo "Database initialised successfully<br/><a href='/'>Retourner à l'index</a>";
		}
		catch(PDOException $e)
		{
			echo $sql . "<br>" . $e->getMessage();
		}

		$conn = null; // EXPLOSION !
	}
	else {
		echo "Missing rawdb.sql !<br/><a href='/'>Retourner à l'index</a>";
	}
}
else {
	echo "Database already initialised !<br/>Remove '.installed' if you want to re-run the scrip<br/><a href='/'>Retourner à l'index</a>";
}
?>
