#include <iostream>
using namespace std;

int IdenticalSymbols(char str[]);

int main()
{
	char str[100];
	cout << "Enter string:" << endl;
	gets_s(str);
	cout << "\nList of words:\n";
	int IdSNum = IdenticalSymbols(str);
	cout << "\nNumber of such words: ";
	cout << IdSNum << endl;

}

int IdenticalSymbols(char str[])
{
	int i = 0, y = 0, LastNum, FirstNum = 0;
	char FirstSymbol = str[0], LastSymbol;
	while (str[i] != '\0') {
		if (isspace(str[i])) { // якщо символ, що перевіряємо є пробілом,
			LastSymbol = str[i - 1]; // то символ, що стоїть перед ним є останнім символом слова
			LastNum = i - 1; // сберігаємо в пам'яті його місцезнаходження в масиві
			if (FirstSymbol == LastSymbol) { // перевіряємо перший та останній символ слова на рівність
				y++; 
				for (int j = FirstNum; j <= LastNum; j++) {
					cout << str[j];
				}
				cout << "\n";
			}
			FirstSymbol = str[i + 1];
			FirstNum = i + 1;
		}
		if (str[i + 1] == '\0') { // якщо наступний символ від символа, що перевіряємо є нуль-символом,
			LastSymbol = str[i]; // то символ, що стоїть перед ним є останнім символом останнього слова
			LastNum = i;
			if (FirstSymbol == LastSymbol) {
				y++;
				for (int j = FirstNum; j <= LastNum; j++) {
					cout << str[j];
				}
				cout << "\n";
			}

		}
		i++;
	}

	return y;
}