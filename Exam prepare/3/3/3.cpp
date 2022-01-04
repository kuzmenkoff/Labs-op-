#include <iostream>
#include <string>
using namespace std;

char** GetString();

int main()
{
	char** Str;
	Str = GetString();

}

char** GetString()
{
	int i = 0;
	char** Str = new char* [i];
	for (int i = 0; i < 1; ++i) {
		Str[i] = new char[100];
	}
	while (Str[i] != "") {
		string* Str = new string[i + 1];
		getline(cin, Str[i]);
		i++;
	} 
	Str[i] = '\0';
	return Str;
}