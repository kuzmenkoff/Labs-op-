#include <vector>
#include <iostream>
#include <ctime>
#include "Header.h"
using namespace std;

BoolVector::BoolVector(int cap)
{
    elements = new int[cap];
    for (int i = 0; i < cap; i++) {
        elements[i] = rand() % 2 + 0;
    }
    capacity = cap;
}

BoolVector::BoolVector(int cap, int* values)
{
    elements = new int[cap];
    for (int i = 0; i < cap; i++) {
        elements[i] = values[i];
    }
    capacity = cap;
}

BoolVector::BoolVector(int cap, int value)
{

    elements = new int[cap];
    for (int i = 0; i < cap; i++) {
        elements[i] = value;
    }
    capacity = cap;
}

void BoolVector::VPrint()
{
    cout << "{ ";
    for (int i = 0; i < capacity; i++) {
        cout << elements[i] << " ";
    }
    cout << "}\n";
}

int BoolVector::GetElement(int i)
{
    if (i < 0 || i >= capacity) {
        return -1;
    }
    return elements[i];
}

int BoolVector::GetCapacity()
{
    return capacity;
}

bool BoolVector::IsPredecessor(BoolVector v)
{
    for (int i = 0; i < capacity; i++) {
        if (elements[i] > v.elements[i]) {
            return false;
        }
    }
    return true;
}

int* BoolVector::operator|(BoolVector v)
{
    BoolVector result(capacity);
    for (int i = 0; i < capacity; i++) {
        if (elements[i] == 0 && v.elements[i] == 0) {
            result.elements[i] = 0;
        }
        else {
            result.elements[i] = 1;
        }
    }
    return result.elements;
}

int* BoolVector::operator^(BoolVector v)
{
    BoolVector result1(capacity);
    for (int i = 0; i < capacity; i++) {
        if (elements[i] == 1 && v.elements[i] == 1) {
            result1.elements[i] = 1;
        }
        else {
            result1.elements[i] = 0;
        }
    }
    return result1.elements;
}