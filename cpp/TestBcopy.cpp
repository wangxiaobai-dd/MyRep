#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
		int i = 0;
		char s[10]="goh\0o\0";
		char d[20];
		char e[20];

		bcopy(s, d, 8);  

		printf("%s\n", d);

		strncpy(e, s, 10);

		printf("%s\n", e);

		return 0;
}

