console.log("js");

$(document).ready(function(){
    nalozi();
    $("li").click(oznaci);// v Javascriptu lahko uporabimo to: document.getElementById("myBtn").addEventListener("click", function() {
    $("tr").click(oznaci1);


    $("#dodaj").click(function(){
        var vnos=$("#vnos").val();
    console.log(vnos);
        var novi = document.createElement("li");//novemu elementu nastavimo znacko
    novi.innerHTML= vnos;//novi element dobi vsebino
        $("ul").append(novi);//zdaj pa ga vpnsemo not
    shrani()
    });
    $("#brisi").click(function(){
        $(".oznacen").remove();//to je Jqueri funkcija.. za Java bi mogli veliko vec
        shrani()
    });
    shrani();


    $("#dodaj2").click(function(){
        var vnos2=$("#vnos2").val();
        var tabela = $('table > tbody');
        var kategorija = $(".oznacen").html();


        console.log(vnos);

        if(vnos2==""){
            vnos2="Blank"
        }
        
        if(kategorija==undefined){
            kategorija="Blank"
        }

        count++;
        var row = document.createElement("tr");
        var td1 = document.createElement("td");
        var td2 = document.createElement("td");
        var td3 = document.createElement("td");
        var td4 = document.createElement("td");


        td1.innerHTML = count;
        td2.innerHTML = vnos2;
        td3.innerHTML = kategorija;
        td4.innerHTML = new Date();

        row.append(td1);
        row.append(td2);
        row.append(td3);
        row.append(td4);
        
        tabela.append(row);	
        shrani();



     /*   var novi = document.createElement("tr");//novemu elementu nastavimo znacko
    novi.innerHTML= vnos;//novi element dobi vsebino
        $("ul").append(novi);//zdaj pa ga vpnsemo not
    shrani()*/
    });
    $("#brisi2").click(function(){
        $(".oznacen1").remove();//to je Jqueri funkcija.. za Java bi mogli veliko vec
        shrani()
    });
    shrani();
});
            var count =0;







function shrani(){
    localStorage.setItem("seznam", $("ul").html());
    localStorage.setItem("tabela",$("tbody").html());
    localStorage.setItem("count",count);

}
function nalozi (){
    if(localStorage.count>0){
        count=localStorage.count;
    }
    if(localStorage.seznam){
        $("ul").html(localStorage.seznam);
    }
    if(localStorage.seznam){
        $("tbody").html(localStorage.tabela);
    }
}

function oznaci(){
    $(".oznacen").removeClass("oznacen"); 
    $(this).toggleClass("oznacen");

}
function oznaci1(){

    $(this).toggleClass("oznacen1");

}