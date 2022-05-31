<?php

	$tabla = "data";
	$username = "root";
	$password1 = "root1234";
	$dbName   = "esp";
	$hostname = "localhost";
	$mysqli = new mysqli($hostname,$username,$password1,$dbName);
	$query = "select * from $tabla ORDER BY fecha DESC LIMIT 1";
	if($result = $mysqli->query($query)){
		while($row = $result->fetch_assoc()){
			$aforo = $row["aforo"];
			$fecha = $row["fecha"];
			$chipid = $row["chipId"];
			$contIn = $row["contIn"];
			$contOut = $row["contOut"];
		}
	}
	?>
<!doctype html>
<html>
	
<head>
<meta charset="utf-8">
<meta http-equiv="refresh" content="2" />
<title>Visitantes</title>
<link rel="stylesheet" href="css/estilos.css" type="text/css"/>
<link rel="stylesheet" href="css/normalize.css" type="text/css"/>
<link href="https://fonts.googleapis.com/css?family=Poppins|Quicksand" rel="stylesheet">
<link href="https://fonts.googleapis.com/css?family=Montserrat" rel="stylesheet">
<link href="https://fonts.googleapis.com/css?family=Gloria+Hallelujah" rel="stylesheet">
<link rel="shortcut icon" href="images/favicon-20180611050006525.ico"/>
<link rel="bookmark" href="images/favicon-20180611050006525.ico"/>
	
</head>

<body>
  <header><p class="text_header">Control de Visitas</p></header>
	<section>
		<article class="article2sin"><p class="tit_fecha_tit">Total aforo: <?php echo $aforo ?> </p> </article> 
		<article class="article2sin"><p class="tit_fecha_tit">Fecha y Hora: <?php echo $fecha ?> </p> </article> 
		
	</section>   
			
	
	<section>
		<article class="article2">
				 <p class="tit_art2">Puerta 1</p>
				 <p class="sub_tit_art2">No de Chip: <?php echo $chipid ?></p>	
				 <p class="sub_tit_art2">Entradas: <?php echo $contIn ?></p>	
				 <p class="sub_tit_art2">Salidas: <?php echo $contOut ?></p>	
		</article>		
		<article class="article2">
				 <p class="tit_art2">Puerta 2</p>
				 <p class="sub_tit_art2">No de Chip:</p>	
				 <p class="sub_tit_art2">Entradas:</p>	
				 <p class="sub_tit_art2">Salidas:</p>		
		</article>				
		<article class="article2">
				 <p class="tit_art2">Puerta 3</p>
				 <p class="sub_tit_art2">No de Chip:</p>	
				 <p class="sub_tit_art2">Entradas:</p>	
				 <p class="sub_tit_art2">Salidas:</p>		
		</article>		
		<article class="article2">
				<p class="tit_art2">Puerta 4</p>
				 <p class="sub_tit_art2">No de Chip:</p>	
				 <p class="sub_tit_art2">Entradas:</p>	
				 <p class="sub_tit_art2">Salidas:</p>		
		</article>			
	</section>
	
	
	<section>
		<article></article>		
		<article></article>	
	
	</section>
<footer></footer>
	
</body>
</html>
