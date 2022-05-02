﻿#include <fstream>
#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

int main()
{
    int n;
    cout << "Select mode:\n1) Create new file\n2) Change old file\n3) Just use last one\n";
    cin >> n;
    CreateFile(n);
    int size = FindSize();
    personnel* workers = ReadInfo(size);
    FileOutput1(workers, size);
    Sort(workers, size);
    FileOutput2();
}
