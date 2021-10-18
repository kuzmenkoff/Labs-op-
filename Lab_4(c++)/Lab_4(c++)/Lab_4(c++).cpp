
#include <iostream>
#include <cmath>


int main()
{
    setlocale(LC_ALL, "Russian");

    int n, i;
    double xi, yi, xim1, yim1, sum, sum0;

    std::cout << "Введите натуральное число n > 1" << std::endl; 
    std::cout << "n = ";
    std::cin >> n; // Воводимо n

    if (n < 1) {
        std::cout << n << " <= 1." << std::endl; // Порівнюємо n з 1
        return 0;
    }  

   

    xi = 1; // Задаємо початкове значення x
    yi = 1; // Задаємо початкове хначення y
    sum0 = 1./2; // Перший член суми при x(1) та y(1)

   
    
    for (i = 2; i <= n; i++) {

            xim1 = xi; // Віддаємо x(n-1) значення x(n)
            yim1 = yi; // Віддаємо y(n-1) значення y(n)
            xi = 3. / 10 * xim1; // Шукаємо x(n) за формулою
            yi = xim1 + yim1; // Шукаємо y(n) за формулою
            sum = sum0 + xi / (1 + abs(yi)); // Знаходимо наступний член та сумуємо його з усіма попередніми
            sum0 = sum;

    }
    std::cout << "S(" << n <<") = " << sum << std::endl; // Виводимо результат

    return 0;
}


