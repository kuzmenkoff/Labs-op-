﻿


#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    setlocale(LC_ALL, "Russian");


    long double a, b, c, d, Max1, Min1, Max2, Min2;
    // Вводимо значенння сторін першого прямокутника
    std::cout << "Введите значение длины сторон первого прямоугольника" << endl;

    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    // Вводимо значенння сторін другого прямокутника
    std::cout << "Введите значение длины сторон второго прямоугольника" << endl;

    std::cout << "c = ";
    std::cin >> c;
    std::cout << "d = ";
    std::cin >> d;
    // Знаходимо більшу та меншу сторони першого прямокутника
    if (a >= b) {
        Max1 = a;
        Min1 = b;
    }
    if (a < b) {
        Max1 = b;
        Min1 = a;
    }
    // Знаходимо більшу та меншу сторони другого прямокутника
    if (c >= d) {
        Max2 = c;
        Min2 = d;
    }
    if (c < d) {
        Max2 = d;
        Min2 = c;
    }
    // Порівнюємо кожну сторону з нулем (кожна сторона мє бути більша нуля)
    if (a <= 0 or b <= 0 or c <= 0 or d <= 0) {
        std::cout << "Данные введены некорректно." << endl;

    }
    // Більші стороні порівнюємо між собою, те саме з меншими сторонами
    else {
        if (Max1 <= Max2 and Min1 <= Min2) {
            std::cout << "Прямоугольник со сторонами a и b можно поместить в прямоуголник со сторонами c и d." << endl;

        }
        if (Max1 > Max2 or Min1 > Min2) {
            std::cout << "Прямоугольник со сторонами a и b нельзя поместить в прямоуголник со сторонами c и d." << endl;
        }
    }
    

    return 0;

}
