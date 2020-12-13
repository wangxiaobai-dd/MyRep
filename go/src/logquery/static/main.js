
var serverTimestamp = 0;
window.onload = GetTime();
var perMin = setInterval(function(){ GetTime(); }, 60000);
var perSec = setInterval(function(){ RefreshTime(); }, 1000);

function OnButton1() {
    console.log("test")
    let formData = $('form').serialize()
    $.ajax(
	{   url:"/query",
	    type: "post",
	    async: true,
	    data: formData,
	    success:function(result){
		console.log(result)
		$("#result").html(result);
	    }
	});
    console.log(formData)
};

function RefreshTime(){
    serverTimestamp++
    $("#servertime").html(TimestampToDate(serverTimestamp));
}

function GetTime(){
    let formData = $('form').serialize()
    $.ajax(
	{
	    url:"/gettime",
	    type:"post",
	    async: true,
	    data: formData,
	    success:function(result){
		console.log(result)
		serverTimestamp = result;
		console.log(TimestampToDate(serverTimestamp))
		$("#servertime").html(TimestampToDate(serverTimestamp));
	    }
	}
    );
    console.log("timer")
}

function TimestampToDate(timestamp){
    var date = new Date(timestamp * 1000);
    Y = date.getFullYear() + '/';
    M = (date.getMonth()+1 < 10 ? '0' + (date.getMonth()+1) : date.getMonth()+1) + '/';
    D = date.getDate() + ' ';
    h = date.getHours() < 10 ? '0' + date.getHours() : date.getHours() + ':';
    m = date.getMinutes() < 10 ? '0' + date.getMinutes() : date.getMinutes() + ':';
    s = date.getSeconds() < 10 ? '0' + date.getSeconds() : date.getSeconds();
    return Y+M+D+h+m+s;
}
