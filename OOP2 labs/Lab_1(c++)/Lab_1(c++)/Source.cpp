#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Header.h"
using namespace std;

vector <string> GetStrings()
{
    vector <string> str;
    string buffer = "";
    do {
        getline(cin, buffer);
        if (buffer.size() > 0) {
            str.push_back(buffer);
        }
    } while (buffer != "");
    return str;
}

void CreateFile(vector <string> str)
{
    ofstream fout;
    fout.open("file.txt");
    int i = 0;
    for (int i = 0; i < str.size(); i++) {
        fout << str[i] << "\n";
    }
    fout.close();
}

vector <string> ReadFile()
{
    string buffer;
    vector <string> newstr;
    ifstream fin;
    fin.open("file.txt");
    char ch;
    while (fin.get(ch)) {
        buffer.push_back(ch);
        if (ch == '\n') {
            newstr.push_back(buffer);
            buffer = "";
        }
    }
    fin.close();
    string s;
    for (int i = 0; i < newstr.size(); i++) {
        s = "(" + to_string(newstr[i].size() - 1) + ") ";
        newstr[i].insert(0, s);
    }
    return newstr;
}

void CreateNewFile(vector <string> newstr)
{
    ofstream newfout;
    newfout.open("NEWfile.txt");
    for (int i = 0; i < newstr.size(); i++)
    {
        newfout << newstr[i];
    }
    newfout.close();
}

void FilesOutput()
{
    char s;
    ifstream read1, read2;
    cout << "\nGenerated file:\n";
    read1.open("file.txt");
    while (read1.get(s)) {
        cout << s;
    }
    read1.close();
    cout << "\nChanged file:\n";
    read2.open("NEWfile.txt");
    while (read2.get(s)) {
        cout << s;
    }
    read2.close();
}