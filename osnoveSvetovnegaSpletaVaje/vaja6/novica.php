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
 
<?php
$izbranId=$_GET["id"];

if($_SESSION["loggedIn"] == true){

for($i=1; $i < 6; $i++){//count($novice)
    if($izbranId==$i){
        echo "<h2>".$novice[$i-1]->naslov."</h2>";
        echo "<h3>".$novice[$i-1]->avtor."</h3>";
        echo "<p>".$novice[$i-1]->datum."</p>";
        echo "<p>".$novice[$i-1]->povzetek."</p>"."</br>";
        echo "<p>".$novice[$i-1]->vsebina."</p>"."</br>";
    
    }

}
if($izbranId>=6 || $izbranId<1){
    echo"Ta novica ne obstaja!!!";
}
}
if($_SESSION["loggedIn"] == false){
    echo "Prijavi se za ogled celotne novice!!!";
}



?>



</body>

</html>