mystr = "hello world"
mystr2 = "hello world2"
my_table = {name = "yxli8", id = 123456}

function a_add_b(a,b)
	return a+b
end


name = "luac"
version = 1
me = {name = "xchen",gender = "female", he=1}
function add(a,b)
	print(a+b)
end

myclass = nil;
function testclass(xMyClass)
	myclass = xMyClass;
	print("hello myclass")
	myclass.myA = 1000;
	print("lua:"..myclass.myA)
	myclass:func();
end

