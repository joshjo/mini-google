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
var url = 'http://localhost:8090/altavista/content?id={0}';
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
        if(json_ans["status"] == "200"){
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