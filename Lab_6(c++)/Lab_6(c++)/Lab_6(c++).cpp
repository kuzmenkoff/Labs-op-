#include <cmath>
#include <iostream>
using namespace std;

bool foo (int x)
{
  int j;
    

  for (j = 2; j < x; j++) {
    if (x % j == 0) {
        return false;
    }

    if (x == j + 1) {
        return true;
    }
  }
    
}
int main()
{
    int n, i;
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите натуральное число n:" << std::endl;
    std::cout << "n = ";
    std::cin >> n;
    std::cout << "Числа-близнецы в интервале от " << n << " до " << n * 2 << ":" << std::endl;
    for (i = n; i <= 2 * n - 2; i++) {
        if (foo(i) && foo(i+2)){

            cout << i << " "<< i + 2 << endl;
        }
        
    }

}
