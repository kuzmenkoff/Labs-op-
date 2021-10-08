

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    float eps, ykm1, yk;

   cout << "Введите значение погрешности (е), при условии что е>0" << endl;
   cout << "e = ";
   cin >> eps; // Вводимо е
    if (eps <= 0) { // Порівнюємо e з нулем
        cout << "Данные введены некорректно." << endl;
        return 0;
    }
    
        ykm1 = 0; // y(0) 
        yk = 1./2; // y(1)
       

        while ((yk - ykm1) >= eps) {
        
            ykm1 = yk; // Віддаємо значення yk ykm1
            yk = ((ykm1 + 1) / (ykm1 + 2)); // Знаходимо y(n+1) та выддаємо це значення yk
            
        }
        cout << "y(n) = " << yk << endl; // Виводимо y(n), для якого виконується нерівність
        cout << "y(n-1) = " << ykm1 << endl; // Виводимо y(n-1)
        cout << "y(n) - y(n-1) = " << yk - ykm1 << endl; // Виводимо різницю y(n) та y(n-1)
        cout << yk - ykm1 << " < " << eps << endl; // Порінюємо різницю y(n) та y(n-1) з e
        cout << "Ответ: " << yk << endl; // Виводимо відповідь

          
            
       

        
        
        return 0;
    
    
   
       
    






}

