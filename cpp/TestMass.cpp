#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main()
{
	char *buffer;
	buffer = getcwd(NULL, 0);
	printf("%s\n", buffer);
	free(buffer);
	char *path;
	path = get_current_dir_name();
	cout<<"path:"<<path<<endl;
	std::string str = path;
	free(path);
	cout << str << endl;


	string value = "a.xml";
	auto iter = value.find(".xml");
	if(iter != std::string::npos)
	{
		cout << value.substr(0, iter) << endl;
	}

	return 0;
}

