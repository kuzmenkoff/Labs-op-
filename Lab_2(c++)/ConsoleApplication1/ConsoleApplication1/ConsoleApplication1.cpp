﻿


#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");


    long double a, b, c, d;

    std::cout << "Введите значение длины сторон первого прямоугольника, при условии что a >= b" << endl;

    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;

    std::cout << "Введите значение длины сторон второго прямоугольника, при условии что c >= d" << endl;

    std::cout << "c = ";
    std::cin >> c;
    std::cout << "d = ";
    std::cin >> d;

    if (a <= c and b <= d ) {
        std::cout << "Прямоугольник со сторонами a и b можно поместить в прямоуголник со сторонами c и d.";

    }
    else {
        std::cout << "Прямоугольник со сторонами a и b нельзя поместить в прямоуголник со сторонами c и d.";
    }

    return 0;

}