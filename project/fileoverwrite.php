 <?php
$myfile = fopen("ready_list.txt", "w") or die("Unable to open file!");
$txt = "";
fwrite($myfile, $txt);
fclose($myfile);
?> 
<html>
	<head>
		<meta http-equiv="refresh" content="6" > 
	</head>
</html>
