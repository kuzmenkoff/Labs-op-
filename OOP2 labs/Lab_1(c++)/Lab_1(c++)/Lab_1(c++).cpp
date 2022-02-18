#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Header.h"
using namespace std;

int main()
{
    vector<string> str = GetStrings();
    CreateFile(str);
    vector <string> newstr = ReadFile();
    CreateNewFile(newstr);
    FilesOutput();
}


