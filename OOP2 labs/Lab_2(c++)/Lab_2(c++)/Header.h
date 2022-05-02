#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void CreateFile(int n); //Створення файлу
bool CheckAge(string date); //Перевірка дати народження перед внесенням даних в головний файл
class personnel; // структура даних
void FileOutput1(personnel* workers, int size); // Вивід головного файлу
void Sort(personnel* workers, int size); // Розподілення даних по файлам відповідно до умови
bool CheckAge2(string date); //Перевірка дати народження перед розподіленням
void FileOutput2(); // Вивід двох останніх файлів
int FindSize(); // Кількість рядків
personnel* ReadInfo(int size); // Зчитування інформації