#pragma once
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

class QuadEq; // ����� ���������� ������
QuadEq* Generate(int num, int mode); // �������� ��� �������� ��������� ������
void ToSolve(QuadEq* Equats, int num); // ���������� �������� ������ ����'����