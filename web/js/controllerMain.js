/* funcion que ejecuta al momento de cargar la ventana main search:*/
window.onload = function() {

  /* hacemos el get desde el localStorage  y lo cargamos en el textfield:*/
   //document.getElementById("search").value = localStorage.getItem("searchValue");

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

String.prototype.format = function() {
    var formatted = this;
    for (var i = 0; i < arguments.length; i++) {
        var regexp = new RegExp('\\{'+i+'\\}', 'gi');
        formatted = formatted.replace(regexp, arguments[i]);
    }
    return formatted;
};

function getParameterByName(name) {
    var url = window.location.href;
    name = name.replace(/[\[\]]/g, '\\$&');
    var regex = new RegExp('[?&]' + name + '(=([^&#]*)|&|#|$)'),
        results = regex.exec(url);
    if (!results) return null;
    if (!results[2]) return '';
    return decodeURIComponent(results[2].replace(/\+/g, ' '));
}

/* Find search */

var http = new XMLHttpRequest();
var url = 'http://localhost:8090/search?q={0}&start={1}';
var params = 'orem=ipsum&name=binny';

/* variables */
var q_parameter = getParameterByName('q');
var start_parameter = getParameterByName('start');
var next_parameter = parseInt(start_parameter)+1;
var prev_parameter = parseInt(start_parameter)-1;
/* variables */

url = url.format(q_parameter, start_parameter);

http.open('GET', url, true);

http.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
http.onreadystatechange = function() {
    if(http.readyState == 4 && http.status == 200) {
        //alert(http.responseText);
        json_ans = JSON.parse(http.responseText);
        // if(json_ans["status"] == "200"){
        if(true) {
            //fill and update time and count result
            document.getElementById("time").innerHTML = json_ans["time"];
            document.getElementById("count").innerHTML = json_ans["total"];
            if(json_ans["next"] != "-1"){
                next_parameter = json_ans["next"];
            }else{
                document.getElementById("nextButton").disabled = true;
            }

            if(json_ans["prev"] != "-1"){
                prev_parameter = json_ans["prev"];
            }else{
                document.getElementById("prevButton").disabled = true;
            }

            var div_result = document.getElementById("result");

            for (var i=0; i< json_ans["results"].length; i++){
                var node = document.createElement("div");
                var id = json_ans["docid"];
                var dbIndex = 12;
                var title = "test";
                var preview = json_ans["preview"];
                //node.innerHTML = message.format(id, title, findWord(body, word), dbIndex);
                node.innerHTML = message.format(id, title, preview, dbIndex);
                node.setAttribute("class","PostResult");
                div_result.appendChild(node);
            }

        }else if(json_ans["status"] == "404"){
            //show json_ans["similar"]
        }
    }else{
        //alert("Fail");
        
        document.getElementById("search").value = q_parameter;

        //var div_result = document.getElementById("result");
//
        //for (var i=0; i<10; i++){
        //    var node = document.createElement("div");
        //    //var textnode = document.createTextNode(message.format(id, title, body, dbIndex));
        //    //var textnode = document.createTextNode(messag.format(title));
        //    //node.appendChild(textnode);
        //    node.innerHTML = message.format(id, title, findWord(body, word), dbIndex);
        //    node.setAttribute("class","PostResult");
        //    div_result.appendChild(node);
        //}

    }
}
http.send(params);

function handleClick(event){

    var http = new XMLHttpRequest();
    var url = ' http://localhost:8090/altavista/getOptions?word=wilder ';
    var params = 'orem=ipsum&name=binny';
    http.open('GET', url, true);

    http.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');

    http.onreadystatechange = function() {
        if(http.readyState == 4 && http.status == 200) {
            
            console.log(http.responseText);
            alert(http.responseText);

        }
    }
    http.send(params);
}

function nextPage(){
    var current_url = window.location.href.split("?")[0];
    location.href = current_url+"?q=" + q_parameter + "&start=" + next_parameter;
}

function prevPage(){
    var current_url = window.location.href.split("?")[0];
    location.href = current_url+"?q=" + q_parameter + "&start=" + prev_parameter;
}

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
    q_parameter = document.getElementById("search").value;
    var current_url = window.location.href.split("?")[0];
    location.href = current_url+"?q=" + q_parameter + "&start=0";

    //var div_result = document.getElementById("result");
//
    //for (var i=0; i<10; i++){
    //    var node = document.createElement("div");
    //    //var textnode = document.createTextNode(message.format(id, title, body, dbIndex));
    //    //var textnode = document.createTextNode(messag.format(title));
    //    //node.appendChild(textnode);
    //    node.innerHTML = message.format(id, title, findWord(body, word), dbIndex);
    //    node.setAttribute("class","PostResult");
    //    div_result.appendChild(node);
    //}
}
/*enlaza y ejecuta la nueva pagina con el contenido en resumen:*/
function linkToContent(){
  /*get the tag a value :*/
    var linkName = document.getElementsByTagName("a").value;
   console.log("value of link clicked"+linkName);
  // alert("value of link clicked"+linkName);
  location.href='content.html';
}
