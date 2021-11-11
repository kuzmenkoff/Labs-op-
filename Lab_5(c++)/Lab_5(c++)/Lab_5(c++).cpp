

#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "Russian");
    int fib1, fib2, fib_sum, i, j;
    std::cout << "Простые числа ряда Фибоначчи: " << std::endl;
    fib1 = 1; // друге число ряду Фібоначчі
    fib2 = 1; // третє число ряду Фібоначчі
    fib_sum = fib1 + fib2; // четверте число ряду Фібоначчі
    i = 2; // початковий порядковий номер
    std::cout << fib1 << "[" << i << "]" << std::endl;
    std::cout << fib2 << "[" << i+1 << "]" << std::endl;  // Виводимо ці числа з їх порядковими номерами
    std::cout << fib_sum << "[" << i+2 << "]" << std::endl;
    
    
    while (fib_sum <= 100) {
        fib_sum = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib_sum;
        i++;
        for (j = 2; j < fib1; j++) {
            if (fib1 % j == 0) { // якщо остача від ділення числа == 0, то число не є простим,
                break; // тому перериваємо цикл
            }
            if (fib1 == j + 1) {
                std::cout << fib1 << "[" << i << "]" << std::endl; // якщо цикл дійде до того моменту, коли fib1 ~ fib1, то виводимо fib1 з порядковим номером 
            }
        }



    }
    return 0;
}

