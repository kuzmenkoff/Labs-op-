

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    long double a, b, c, d, diag1, diag2;

    std::cout << "Введите значение длины сторон первого прямоугольника" << endl;

    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;

    std::cout << "Введите значение длины сторон второго прямоугольника" << endl;

    std::cout << "c = ";
    std::cin >> c;
    std::cout << "d = ";
    std::cin >> d;

    diag1 = sqrt(pow(a, 2) + pow(b, 2));
    diag2 = sqrt(pow(c, 2) + pow(d, 2));

    if (diag1 <= diag2) {
        std::cout << "Прямоугольник со сторонами a и b можно поместить в прямоуголник со сторонами c и d.";
    }
    else {
        std::cout << "Прямоугольник со сторонами a и b нельзя поместить в прямоуголник со сторонами c и d.";
    }

    return 0;
        


    

}

