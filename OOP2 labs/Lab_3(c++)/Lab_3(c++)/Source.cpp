#include <string>
#include <iostream>
#include <ctime>
#include "Header.h"
using namespace std;

class QuadEq {
public:
	int a, b, c; // ����������� 
	string status; // �������� ������ ������
	void print() { // ������� ��������� ������� � �������
		cout << a << "x^2";
		if (b >= 0) {
			cout << "+";
		}
		cout << b << "x";
		if (c >= 0) {
			cout << "+";
		}
		cout << c << "=0" << endl;
	}
};

QuadEq* Generate(int num, int mode) {
	srand((unsigned int)time(NULL));
	QuadEq* Equats = new QuadEq [num]; // ��'������� ������
	if (mode == 1) { // ��������� ���������
		cout << "\nGenerated equations:\n";
		for (int i = 0; i < num; i++) {
			Equats[i].a = rand() % 19 - 9;
			Equats[i].b = rand() % 19 - 9;
			Equats[i].c = rand() % 19 - 9;
			cout << i + 1 << ") ";
			Equats[i].print();
		}
	}
	else if (mode == 2) { // �������� � ���������
		for (int i = 0; i < num; i++) {
			cout << i + 1 << ": a = ";
			cin >> Equats[i].a;
			cout << "b = ";
			cin >> Equats[i].b;
			cout << "c = ";
			cin >> Equats[i].c;
		}
		cout << "\nEntered equations:\n";
		for (int i = 0; i < num; i++) { 
			cout << i + 1 << ") ";
			Equats[i].print();
		}
	}
	else {
		cout << "Error!";
		exit(0);
	}
	cout << endl;
	return Equats;
}

void ToSolve(QuadEq* Equats, int num)
{
	double d;
	for (int i = 0; i < num; i++) {
		d = sqrt(Equats[i].b) - 4 * Equats[i].a * Equats[i].c; // ��������� �����������
		// � ��������� �� �������� ������������ ����쳺�� �� �� ������� ���� ����'����
		if (d < 0) {
			Equats[i].status = "2 valid solutions!";
		}
		else if (d == 0) {
			Equats[i].status = "1 valid solution!";
		}
		else {
			Equats[i].status = "no valid solutions!";
		}
		cout << i + 1 << ") " << Equats[i].status << endl;
	}
}