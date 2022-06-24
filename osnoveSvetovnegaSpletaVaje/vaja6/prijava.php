<?php
include_once 'baza.php';

session_start(); //zacetek seje

$napaka= "";

if(isset($_POST["login"])){
$username=$_POST["username"];
$password =$_POST["password"];
//echo "prijavil se je: " . $username ."<br/>"; to je blo samo za vajo



for($i=0; $i < count($uporabniki); $i++){
if($uporabniki[$i]->username==$username && $uporabniki[$i]->geslo==$password){// morem preverit ce obstaja uporabnik s tem imenom in geslom
    



    $_SESSION["user"]=$username;
    $_SESSION["loggedIn"] = true;
header("Location: index.php");
//die();//neha se koda predvajat
}
else{
    
    $_SESSION["loggedIn"] = false;
    $napaka="Geslo ali Ime nista pravilna";//ce uporabnik ne obstaja mu izpise da geslo ali ime ni pravilno

}
}
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>OSS vaja 6</title>
    <meta charset="UTF-8"/> 

</head>
<body>
 
<form action="prijava.php" method="POST">
    Uporabniško ime: <input type="text" name= "username" /> <br/>
    geslo: <input type="password" name="password" /><br/>
    <input type="submit" name="login" value="Prijavi"/>
<?php echo $napaka; ?>
</form>



</body>

</html>