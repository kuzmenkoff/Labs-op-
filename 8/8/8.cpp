#include <string>
#include <iostream>
using namespace std;
string* GetStrings(int strNum);
int* Count(string* str, int strNum);
string** SplitString(string* str, int strNum, int* counter);
string** DeleteWords(string** words, int strNum, int* counter, int len);
int FindLongest(string** words, int strNum, int* counter);

int main()
{
    int strNum, len;
    cout << "Enter number of strings:";
    cin >> strNum;
    string* str = GetStrings(strNum);
    int* counter = Count(str, strNum);
    string** words = SplitString(str, strNum, counter);
    cout << "Enter length:";
    cin >> len;
    cout << "New strings:";
    string** newwords = DeleteWords(words, strNum, counter, len);
    int max = FindLongest(words, strNum, counter);
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
    string** words = new string* [strNum];
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

string** DeleteWords(string** words, int strNum, int* counter, int len)
{
    for (int i = 0; i < strNum; i++) {
        if (i % 2 != 0) {
            for (int j = 0; j < counter[i]; j++) {
                if (words[i][j].length() < len) {
                    words[i][j] = "";
                }
            }
        }
        else {
            string tmp = words[i][counter[i] - 1];
            for (int j = counter[i] - 1; j > 0; j--) {
                words[i][j] = words[i][j - 1];
            }
            words[i][0] = tmp;
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

int FindLongest(string** words, int strNum, int* counter)
{
    int max = 0, MaxStr = 0, len;
    for (int i = 0; i < strNum; i++) {
        len = 0;
        for (int j = 0; j < counter[i]; j++) {
            len += words[i][j].length();
        }
        if (len > max) {
            max = len;
            MaxStr = i;
        }
    }
    cout << "\n" << MaxStr + 1 << " )";
    for (int j = 0; j < counter[MaxStr]; j++) {
        if (words[MaxStr][j] != "") {
            cout << words[MaxStr][j] << " ";
        }
    }
    cout << "- is longest!!!\n";
    return MaxStr;
}