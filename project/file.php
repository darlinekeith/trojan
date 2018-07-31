<?php
 $conn = new mysqli('localhost','root','','data');
$file = fopen("ready_list.txt", "r");

while (!feof($file)) {
	$content = fgets($file);
	$array = explode(",", $content);
	list($function,$result) = $array;
	$sql = "INSERT INTO `table_task`(`function`,`result`) VALUES ('$function','$result')";
	$conn->query($sql);
}
 
    $txt = "";
    fwrite($file, $txt);
    fclose($file);
?>
<html>
	<head>
		<meta http-equiv="refresh" content="60" >
	</head>
</html>
