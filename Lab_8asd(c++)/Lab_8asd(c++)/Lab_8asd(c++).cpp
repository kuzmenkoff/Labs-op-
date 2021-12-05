#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void ArrayPrint(float arr[], int size);
float SortArray(float Array[], int size);

int main()
{
	setlocale(LC_ALL, "Russian");
	int Matrix[5][7], i, j, y;
	float ColumnSum, ArithmeticMean, Array[7], Array2[7];
	srand((unsigned int)time(NULL));
	// Ініціюємо Matrix[][]
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 7; j++) {
			Matrix[i][j] = rand() % 100 - 50; 
		}
	}
	// Знаходимо середнє арифметичне від'ємних елементів кожного рядка та вносимо у масив
	for (j = 0; j < 7; j++) {
		y = 0;
		ColumnSum = 0;
		for (i = 0; i < 5; i++){
			if (Matrix[i][j] < 0) {
				ColumnSum += Matrix[i][j];
				y++;
			}
		}
		ArithmeticMean = ColumnSum / y;
		Array[j] = ArithmeticMean;
		Array2[j] = ArithmeticMean;
	}
	// Сортуємо масив
	SortArray(Array2, 7);

	// ======== ВИВІД ==========
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 7; j++) {
			cout << " " << Matrix[i][j] << " ";

		}
		cout << " " << endl;
	}
	cout << "\n";
	ArrayPrint(Array, 7);
	cout << "Отсортированый массив по убыванию:" << endl;
	ArrayPrint(Array2, 7);
}

void ArrayPrint(float arr[], int size)
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "   ";
	}
	cout << "\n";
}

float SortArray(float Array[], int size) {
	int i = 0, j;
	float tmp;
	while (i < size - 1 && Array[i] != 0) {
		j = 0;
		while (j < size - 1 - i && Array[j] != 0) {
			if (Array[j + 1] > Array[j]) {
				tmp = Array[j];
				Array[j] = Array[j + 1];
				Array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return Array[size];
}