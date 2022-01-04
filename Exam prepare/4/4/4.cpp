#include <cstring>
#include <string>
#include <iostream>
using namespace std;

string* GetString(int StrNum);
string* DeleteSymbols(string* Str, int StrNum);

int main()
{
	string* Str;
    int StrNum;
    cout << "Enter the number of strings:\n";
    cin >> StrNum;
	Str = GetString(StrNum);
	Str = DeleteSymbols(Str, StrNum);


}

string* GetString(int StrNum)
{
	string* Str = new string [StrNum];
	for (int i = 0; i < StrNum; i++) {
		cin >> Str[i];
	}
	return Str;
}

string* DeleteSymbols(string* Str, int StrNum)
{
	int counter = 0;

    for (int i = 0; i < StrNum; i++) {
		for (int j = 0; j < Str[i].length(); j++) {
			counter = 0;
			for (int x = 0; x < StrNum; x++) {
				for (int y = 0; y < Str[i].length(); y++) {
					//string first = Str[i].find(j, 1);
					//string second = Str[x].find(y, 1);
					if (Str[i].find(j, 1) == Str[x].find(y, 1)) {
						counter++;
					}

				}
			}
			if (counter > 5) {
				cout << Str[i].find(j, 1) << " - " << counter << endl;
			}
		}
	}

	
	return Str;
}
