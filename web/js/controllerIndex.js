
function autocomplete(inp, arr) {

  /*la funcion autocomplete toma dos argumentos,
  el archivo de texto y una arreglo de posibles valores:*/

  var currentFocus;

  /*ejecuta una funcion cuando alguien escribe en el textfield:*/
  inp.addEventListener("input", function(e) {

      var a, b, i, val = this.value;
      /*cierra cualquier lista ya abierta de valores autocompletados:*/
      closeAllLists();
      if (!val) { return false;}
      currentFocus = -1;

      /*crear un elemento DIV que contendra los items con valores:*/
      a = document.createElement("DIV");
      a.setAttribute("id", this.id + "autocomplete-list");
      a.setAttribute("class", "autocomplete-items");
      /*añade el elemento DIV  como hijo del contenedor autocomplete:*/
      this.parentNode.appendChild(a);
      /*recorrer para cada item en el datasuggest...*/
      for (i = 0; i < arr.length; i++) {
        /*comparar si el item empieza con la mismo caracter en el textfield :*/
        //console.log(tildes_unicode(arr[i]).substr(0, val.length).toUpperCase()+"="+val.toUpperCase());

        if (tildes_unicode(arr[i]).substr(0, val.length).toUpperCase() == val.toUpperCase()) {
          /*crea un DIV para cada elemento que hace mach:*/
          b = document.createElement("DIV");
          /*hacer en negrita las letras coencidentes:*/

          //b.innerHTML = "<strong>" + arr[i].substr(0, val.length) + "</strong>";
          //b.innerHTML += arr[i].substr(val.length); //valores que no conenciden
          b.innerHTML = tildes_unicode(arr[i]).substr(0,val.length);
          b.innerHTML += "<strong>"+tildes_unicode(arr[i]).substr(val.length)+"</strong>";

          /*insertar un inputfield(hidden)  que contendra los valores del item actual:*/
          b.innerHTML += "<input type='hidden' value='" + arr[i] + "'>";

          /*ejecutar una funcion cuando alguien hace click en el item value(DIV):*/
          b.addEventListener("click", function(e) {
              /*insertar el valor para autocompletar el textfield:*/
              inp.value = this.getElementsByTagName("input")[0].value;
              /*cerar la lista autocompletada de valores,
              (o cualquier otra lista de valores autocompletados:*/
              closeAllLists();
          });
          a.appendChild(b); //añadir al DIV
        }
      }
  });

  /*ejecuta una funcion presionando una tecla del teclado:*/
  inp.addEventListener("keydown", function(e) {
      var x = document.getElementById(this.id + "autocomplete-list");

      if (x) x = x.getElementsByTagName("div");
      console.log("x--> "+x);
      if (e.keyCode == 40) { //flechica abajo
        /*Si el cursor del flecha abajo es presionado
        incrementar la variable currentFocus :*/
        currentFocus++;
        /* asi hacemos que el elemento sea mas visible:*/
        addActive(x);
      } else if (e.keyCode == 38) { //flechita arriba
        /* Si la flechita arriba es presionada
        disminuimos la varible currentFocus:*/
        currentFocus--;
        /*activar la visibilidad:*/
        addActive(x);
      } else if (e.keyCode == 13) {
        /*si la tecla ENTER es presionado, evitar que se envíe el formulario,*/
        e.preventDefault();
        if (currentFocus > -1) {
          /*simular un click en el item activo:*/
          if (x) x[currentFocus].click();
        }
      }
  });

  function addActive(x) {
    /* funcion para clasificar los items como "active":*/
    if (!x) return false;
    /*iniciar eliminacion de la clase "active" en todos los items:*/
    removeActive(x);
    console.log("currentFocus : "+currentFocus);
    if (currentFocus >= x.length) currentFocus = 0;
    if (currentFocus < 0) currentFocus = (x.length - 1);
    /*add class "autocomplete-active":*/
    x[currentFocus].classList.add("autocomplete-active");
  }
  function removeActive(x) {
    /*a function to remove the "active" class from all autocomplete items:*/
    for (var i = 0; i < x.length; i++) {
      x[i].classList.remove("autocomplete-active");
    }
  }

  function closeAllLists(elmnt) {
    /*cierra todo la lista autocomplete en el documento,
    excepto el que pasó como argumento:*/
    var x = document.getElementsByClassName("autocomplete-items");
    for (var i = 0; i < x.length; i++) {
      if (elmnt != x[i] && elmnt != inp) {
        x[i].parentNode.removeChild(x[i]);
      }
    }
  }
  /* ejecuta la funcion cuando alaguien hace click en el documento:*/
  document.addEventListener("click", function (e) {
      closeAllLists(e.target);
  });
}
/* funcion para validar acentos y ñ para caracteres en español:*/
function tildes_unicode(str){
  str = str.replace('á','\u00e1');
  str = str.replace('é','\u00e9');
  str = str.replace('í','\u00ed');
  str = str.replace('ó','\u00f3');
  str = str.replace('ú','\u00fa');

  str = str.replace('Á','\u00c1');
  str = str.replace('É','\u00c9');
  str = str.replace('Í','\u00cd');
  str = str.replace('Ó','\u00d3');
  str = str.replace('Ú','\u00da');

  str = str.replace('ñ','\u00f1');
  str = str.replace('Ñ','\u00d1');
  return str;
}

/*
 *Funcion para reemplazar y eliminar las tilde y la ñ
 */

function eliminar_tildes(str){

  str = str.replace('á','a');
  str = str.replace('é','e');
  str = str.replace('í','i');
  str = str.replace('ó','o');
  str = str.replace('ú','u');

  str = str.replace('Á','A');
  str = str.replace('É','E');
  str = str.replace('Í','I');
  str = str.replace('Ó','O');
  str = str.replace('Ú','U');

  str = str.replace('ñ','n');
  str = str.replace('Ñ','N');
  return str;
}
/* una array que contiene todos las posibles sugerencias */
var dataSuggest = ["poco","pocoyo","pocoyó","pocophone f1","pocoyo en español","pocoyo en espanol","Pocsi","poco a poco","poco  tarea","pocoyo para colorear"];

/* inicializar la funcion autocompletado en el elemento "myInput", y pasar los dataSuggestcomo posibles autocompletados:*/
autocomplete(document.getElementById("myInput"), dataSuggest);


//consulta get data string buscado
function querySearch(){
  var value = document.getElementById("myInput").value;
  console.log("data "+value);
  window.localStorage.setItem("searchValue", value); //guardar el valor en el localStorage
  location.href='main.html';
}