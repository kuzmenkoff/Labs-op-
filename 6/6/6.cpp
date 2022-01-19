#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

string* GetStrings(int strNum);
int* Count(string* str, int strNum);
string** SplitString(string* str, int strNum, int* counter);
string** DeleteWords(string** words, int strNum, int* counter);
string FindLongest(string** newwords, int strNum, int* counter);

int main()
{
    int strNum;
    cout << "Enter number of strings:";
    cin >> strNum;
    string* str = GetStrings(strNum);
    int* counter = Count(str, strNum);
    string** words = SplitString(str, strNum, counter);
    string** newwords = DeleteWords(words, strNum, counter);
    string LongestW = FindLongest(newwords, strNum, counter);

}

string* GetStrings(int strNum)
{
    string* str = new string[strNum];
    string line = "";
    getline(cin, line);
    for (int i = 0; i < strNum; i++) {
        getline(cin, line);
        str[i] = line;
    }
    return str;
}

int* Count(string* str, int strNum)
{
    int* counter = new int[strNum];
    for (int i = 0; i < strNum; i++) {
        counter[i] = 1;
        for (int j = 0; j < str[i].length(); j++) {
            if (isspace(str[i][j])) {
                counter[i]++;
            }
        }
    }
    return counter;
}

string** SplitString(string* str, int strNum, int* counter)
{
    string** words = new string * [strNum];
    for (int i = 0; i < strNum; i++) {
        words[i] = new string[counter[i]];
        int index = 0;
        for (int j = 0; j < str[i].length(); j++) {
            if (isspace(str[i][j])) {
                index++;
                continue;
            }
            words[i][index] += str[i][j];
        }
    }
    return words;
}

string** DeleteWords(string** words, int strNum, int* counter)
{
    for (int i = 0; i < strNum; i++) {
        for (int j = 0; j < counter[i]; j++) {
            if (words[i][j][0] == '(' && words[i][j][words[i][j].length() - 1] == ')') {
                words[i][j] = "";
            }
        }
    }
    cout << endl;
    for (int i = 0; i < strNum; i++) {
        for (int j = 0; j < counter[i]; j++) {
            if (words[i][j] != "") {
                cout << words[i][j] << " ";
            }
        }
        cout << endl;
    }
    return words;
}

string FindLongest(string** newwords, int strNum, int* counter)
{
    int MaxLen = 0;
    string LongestW;
    for (int i = 0; i < strNum; i++) {
        for (int j = 0; j < counter[i]; j++) {
            if (newwords[i][j].length() > MaxLen) {
                MaxLen = newwords[i][j].length();
                LongestW = newwords[i][j];
            }
        }
    }
    cout << "\nLongest:  " << LongestW;
    return LongestW;
}


