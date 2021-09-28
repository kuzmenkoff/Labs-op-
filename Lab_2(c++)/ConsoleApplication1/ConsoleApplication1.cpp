


#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");


    long double a, b, c, d, Max1, Min1, Max2, Min2;

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

    Max1 = max(a, b);
    Min1 = min(a, b);
    Max2 = max(c, d);
    Min2 = min(c, d);

    if (a <= 0 or b <= 0 or c <= 0 or d <= 0) {
        std::cout << "Данные введены некорректно." << endl;

    }
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
