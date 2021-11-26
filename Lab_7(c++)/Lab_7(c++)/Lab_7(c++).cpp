#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void ArrayPrint(int arr[], int size, int number); // Вивід масиву
bool ISMult3(int C); // Перевірка на кратність 3
bool ISNotMult5(int C); // Перевірка на некратність 5

int main()
{
    setlocale(LC_ALL, "Russian");
    int csize, i, dsize = 0, j = 0; 
    cout << "Введите размер массива:" << endl;
    cin >> csize;
    // Присвоюємо першому масиву розмір
    int* C = new int[csize];
    srand((unsigned int)time(NULL));
    // Цикл генерує перший массив за заданим розміром, а також рахує кількість елементів другого
    for (i = 0; i < csize; i++) {
        C[i] = rand() % 100;
        if (ISMult3(C[i]) && ISNotMult5(C[i])) {
            dsize++;
        }
    }
    // Присвоюємо другому масиву розмір
    int* D = new int[dsize];
    // Цикл знаходить усі елементи другого массиву 
    for (i = 0; i < csize; i++) {
        if (ISMult3(C[i]) && ISNotMult5(C[i])) {
            D[j] = C[i];
            j++;
        }
    }
    // Цикл знаходить суму усіх елементів другого масиву
    int Sum = D[0];
    for (i = 1; i < dsize; i++) {
        Sum += D[i];
    }
    // Третій масив, що складається з елементів першого масиву збільшених на Sum
    int* E = new int[csize];

    for (i = 0; i < csize; i++) {
        E[i] = C[i] + Sum;
    }
    

    ArrayPrint(C, csize, 1);
    ArrayPrint(D, dsize, 2);
    cout << "Сумма всех элементов массива №2" << endl;
    cout << Sum << endl;
    ArrayPrint(E, csize, 3);
 
}

void ArrayPrint(int arr[], int size, int number) 
{
    cout << "Массив №" << number << "[" << size << "]:" << endl;
    cout << "{";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "}" << endl;
}

bool ISMult3(int C) {
    if (C % 3 == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool ISNotMult5(int C) {
    if (C % 5 == 0) {
        return false;
    }
    else {
        return true;
    }
}