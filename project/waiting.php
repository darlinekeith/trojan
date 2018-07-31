<?php
// Connects to your Database
mysql_connect("localhost", "root", "") or die(mysql_error());
mysql_select_db("data") or die(mysql_error());
//checks cookies to make sure they are logged in
if(isset($_COOKIE['ID_my_site']))
{
$username = $_COOKIE['ID_my_site'];
$pass = $_COOKIE['Key_my_site'];
$check = mysql_query("SELECT * FROM users WHERE username = '$username'")or die(mysql_error());
while($info = mysql_fetch_array( $check ))
{
//if the cookie has the wrong password, they are taken to the login page
if ($pass != $info['password'])
{ header("Location: login.php");
}
//otherwise they are shown the admin area
else
{
echo "<a href=logout.php>Logout</a>";
}
}
}
else
//if the cookie does not exist, they are taken to the login screen
{
header("Location: login.php");
}
?>
<html>
<head>
<title>Trojan admin</title>
<link rel="stylesheet" href="images/style.css" type="text/css" />
<style type="text/css">
body {
  color: black;
}
  table, th, td{
    border: 1px solid black;

  }
</style>
</head>
<body>
<div class="content">
  <div class="preheader">
    <div class="padding"> <a href=logout.php>Admin Logout</a></div>
  </div>
  <div class="header">
    <div class="title">TROJAN PROJECT</div>
    <div class="slogan">ADMINISTRATOR</div>
  </div>
  <div id="nav">
    <ul>
      <li><a href="index.php">Ready Jobs</a></li>
      <li><a href="high.php">Highest success rates</a></li>
      <li><a href="fail.php">Highest failure</a></li>
    <li><a href="waiting.php">Waiting jobs</a></li>    </ul>
  </div>
  <div class="main_content">
    <div class="sd_right">
      <div class="text_padding">
        <!--
    -->
      </div>
    </div>
  
    <div class="sd_left">
      <div class="text_padding" style="height:400px;">
        <h2>Trojan word task server</h2>
<?php
 /* $den = mysql_query("SELECT *FROM ``");
 echo "<table>\n";
 while ($line = mysql_fetch_array($den, MYSQL_ASSOC)) {
  echo "\t<tr>\n";
  foreach ($line as $col_value) {
    echo "\t\t<td>$col_value</td>\n";
  }
  echo "\t</tr>\n";
 }
 echo "</table>\n"; */
?>
      </div>
    </div>
    <div class="footer">
      <div class="padding">TROJAN </div>
    </div>
  </div>
</div>
</body>
</html>
