#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector <string> GetStrings(); // ��� ������
void CreateFile(vector <string> str); // �������� ����� � ����
vector <string> ReadFile(); // ������� ���� �� ������� �����
void CreateNewFile(vector <string> newstr); // ������� ������� ����� � ����� ����
void FilesOutput(); // �������� ����� � �������

