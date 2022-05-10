#include <vector>
#include <iostream>
#include <ctime>
#include "Header.h"
using namespace std;

int main()
{
    srand((unsigned int)time(NULL));
    int cap;
    cout << "Enter the capacity of vectors: ";
    cin >> cap;
    if (cap <= 0) {
        cout << "Error!";
        exit(0);
    }
    int* values = new int[cap];
    for (int i = 0; i < cap; i++) {
        cin >> values[i];
    }
    BoolVector V1(cap, values);
    cout << "V1: "; V1.VPrint();
    BoolVector V2(cap);
    cout << "V2: "; V2.VPrint();
    BoolVector V3 (cap, V1 | V2);
    cout << "V3 = V1 | V2 : "; V3.VPrint();
    BoolVector V4 (cap, V1 ^ V3);
    cout << "V4 = V1 ^ V3 : "; V4.VPrint();
    if (V4.IsPredecessor(V3)) {
        cout << "\nV4 is predecessor for V3!\n";
    }
    else {
        cout << "\nV4 is not predecessor for V3!\n";
    }
}


