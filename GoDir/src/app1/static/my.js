function OnButton1() {
     console.log("test")
    var xhr = new XMLHttpRequest();

    xhr.onreadystatechange = function () {
	if (xhr.readyState == 4) {
	    if (xhr.status == 200) {
		var oTxt = document.getElementById('txt');
		oTxt.value = xhr.responseText;
	    }   
	}   
    };  
    xhr.open('get', '/query', true);
    xhr.send();
};
