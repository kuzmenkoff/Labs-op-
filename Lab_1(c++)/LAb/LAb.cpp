#include <iostream>
#include <cmath>
using namespace std;

int main()

{
	setlocale(LC_ALL, "Russian");
	std::cout << "Ведите три числа, из которых хотите найти среднее геометрическое." << endl;
	long double a, b, c, d, x, y;
	std::cin >> a; 
	std::cin >> b; 
	std::cin >> c; 
	d = pow(a * b * c, 1.0 / 3.); 
	x = modf(d, &y);
	std::cout << "Целая и дробная части числа " << d << " равны " << y << " и " << x;

	return 0;
}