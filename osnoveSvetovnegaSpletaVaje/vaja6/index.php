<?php
include_once 'baza.php';
session_start();
?>

<!DOCTYPE html>
<html>
<head>
    <title>OSS vaja 6</title>
    <meta charset="UTF-8"/> 

</head>
<body>
    <h1>Novice</h1>

<?php

if(isset ($_SESSION["user"])){
    $_SESSION["loggedIn"] = true;
echo "Pozdravljen, ". $_SESSION["user"]. "</br>";
echo"<a href='odjava.php'> Odjava </a>";//odjava
}
else{
    echo"<a href='prijava.php'>Prijavi se </a>";
    $_SESSION["loggedIn"] = false;

}


for($i=1; $i < count($novice); $i++){
    echo "<h2>".$novice[$i-1]->naslov."</h2>";
    echo "<h3>".$novice[$i-1]->avtor."</h3>";
    echo "<p>".$novice[$i-1]->datum."</p>";
    echo "<p>".$novice[$i-1]->povzetek."</p>"."</br>";


        echo "<a href='novica.php?id=$i'><p>"."preberi vse"."</p></a>";

}






?>

</body>

</html>