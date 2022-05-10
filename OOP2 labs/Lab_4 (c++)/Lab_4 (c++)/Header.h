#pragma once
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;

class BoolVector
{
private:
	int* elements;
	int capacity;
public:
	BoolVector(int cap);
	BoolVector(int cap, int* values);
	BoolVector(int cap, int value);
	void VPrint();
	int GetElement(int i);
	int GetCapacity();
	bool IsPredecessor(BoolVector v);
	int* operator|(BoolVector v); 
	int* operator^(BoolVector v);
};


