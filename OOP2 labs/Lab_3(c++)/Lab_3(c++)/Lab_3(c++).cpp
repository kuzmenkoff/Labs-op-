#include <string>
#include <iostream>
#include <ctime>
#include "Header.h"
using namespace std;

int main()
{
    int num, mode;
    cout << "Enter number of equations: ";
    cin >> num;
    cout << "\n1.Random generation\n2.Enter yourself\n\nChoose mode: ";
    cin >> mode;
    QuadEq* Equats = Generate(num, mode);
    ToSolve(Equats, num);
}
