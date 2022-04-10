#pragma once
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

class QuadEq; // Класс квадратних рівнянь
QuadEq* Generate(int num, int mode); // Введення або віпадкова генерація рівнянь
void ToSolve(QuadEq* Equats, int num); // Визначення наявності дійсних розв'язків