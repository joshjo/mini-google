
/* funcion que ejecuta al momento de cargar la ventana main search:*/
window.onload = function() {

  /* hacemos el get desde el localStorage  y lo cargamos en el textfield:*/
   document.getElementById("search").value = localStorage.getItem("searchValue");

}


var message = "\
    <a href='/getDocument/../{0}/../content.html'>{1}</a>\
        <div class='PostBody'>\
            {2}\
        </div>\
        <div class='PostFooter'>\
        id='{0}' dbindex='{3}'\
    </div>";
    var messag = "${title}";
var title = "First Post";
var id = "26232";
var dbIndex = "12235";
var word = "ex";
var maxLetters = 50;
var body = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor \
incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud \
exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute \
irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla \
pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia \
deserunt mollit anim id est laborum.";

function handleClick(event){
    var http = new XMLHttpRequest();
    var url = 'https://httpbin.org/get';
    var params = 'orem=ipsum&name=binny';
    http.open('GET', url, true);

    http.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');

    http.onreadystatechange = function() {
        if(http.readyState == 4 && http.status == 200) {
            alert(http.responseText);
        }
    }
    http.send(params);
}

String.prototype.format = function() {
    var formatted = this;
    for (var i = 0; i < arguments.length; i++) {
        var regexp = new RegExp('\\{'+i+'\\}', 'gi');
        formatted = formatted.replace(regexp, arguments[i]);
    }
    return formatted;
};

function cutMessage(message, init, end){
    return message.substring(init, end);
}

function findWord(message, word){
    var str_split = message.split(word);
    if (message.length < maxLetters) return message.join("<b><em><u>"+word+"</u></em></b>");
    if (str_split.length == 1 ) return cutMessage(message, 0, maxLetters);
    if (str_split[0].length < maxLetters) return cutMessage(str_split.join("<b><em><u>"+word+"</u></em></b>"), 0, maxLetters+23);
    else {
        console.log(cutMessage(str_split[0],0,maxLetters/3));
        console.log(cutMessage(str_split.join("<b><em><u>"+word+"</u></em></b>"), str_split[0].length - (maxLetters/3), str_split[0].length + (maxLetters/3)));
        return cutMessage(str_split[0],0,maxLetters/3) +" ... " + cutMessage(str_split.join("<b><em><u>"+word+"</u></em></b>"), str_split[0].length - (maxLetters/3), str_split[0].length + (maxLetters/3)+24);
    }
}

function handlePosts(){
    //var elements = document.getElementById("result");
    //for (var i=0; i<elements.length; i++){
    //    var UnBoton = document.createElement("LI");
    //    document.createTextNode ('<input type="button" name="boton7" value=" 7 ">');
    //    elements.appendChild(UnBoton);
    //}
    var div_result = document.getElementById("result");
    for (var i=0; i<10; i++){
        var node = document.createElement("div");
        //var textnode = document.createTextNode(message.format(id, title, body, dbIndex));
        //var textnode = document.createTextNode(messag.format(title));
        //node.appendChild(textnode);
        node.innerHTML = message.format(id, title, findWord(body, word), dbIndex);
        node.setAttribute("class","PostResult");
        div_result.appendChild(node);
    }
}
/*enlaza y ejecuta la nueva pagina con el contenido en resumen:*/
function linkToContent(){
  /*get the tag a value :*/
    var linkName = document.getElementsByTagName("a").value;
   console.log("value of link clicked"+linkName);
  // alert("value of link clicked"+linkName);
  location.href='content.html';
}
