<?php
$tabla = "data";
		$username = "root";
		$password1 = "root1234";
		$dbName   = "esp";
		$hostname = "localhost";
		$conn = mysqli_connect($servername, $username, $password1, $dbName);
		if (!$conn) {
			die("Connection failed: " . mysqli_connect_error());
	  	}	
$chipid = $_POST ['chipid'];
$aforo = $_POST ['aforo'];
$door= $_POST['door'];
if ($door=="1")
	{
		$act="Entrada";
		$contIn=$contIn+1;
		$vis=$vis+1;
	}
else{
		$act="Salida";
		$afGen=$afGen--;
		$contOut=$contOut+1;
	}

/*mysql_query("INSERT INTO `esp`.`data` (`id`, `chipId`, `fecha`, `aforo`, `act`) VALUES (NULL, '$chipid', CURRENT_TIMESTAMP, '$aforo', '$act');"); PAra uso de sensor almacenes web de una sola Puerta*/

$sql = "INSERT INTO `esp`.`data` (`chipId`, `aforo`, `act`, `contIn`, `contOut`, `vis`) VALUES ('$chipid', '$aforo', '$act', '$contIn', '$contOut', '$vis')";
if (mysqli_query($conn, $sql)) {
	echo "Datos ingresados correctamente.";
} else {
	echo "Error: " . $sql . "<br>" . mysqli_error($conn);
}
mysql_close(); // Para uso de un CC de varias entradas


?>



