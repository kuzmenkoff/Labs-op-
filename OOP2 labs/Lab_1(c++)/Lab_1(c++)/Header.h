#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector <string> GetStrings(); // Ввід тексту
void CreateFile(vector <string> str); // Заносимо текст у файл
vector <string> ReadFile(); // Зчитуємо файл та змінюємо текст
void CreateNewFile(vector <string> newstr); // Вносимо змінений текст у новий файл
void FilesOutput(); // Виводимо файли у консоль

