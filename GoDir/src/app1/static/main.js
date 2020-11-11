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
