#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void CreateFile(int n); //��������� �����
bool CheckAge(string date); //�������� ���� ���������� ����� ��������� ����� � �������� ����
class personnel; // ��������� �����
void FileOutput1(personnel* workers, int size); // ���� ��������� �����
void Sort(personnel* workers, int size); // ����������� ����� �� ������ �������� �� �����
bool CheckAge2(string date); //�������� ���� ���������� ����� ������������
void FileOutput2(); // ���� ���� ������� �����
int FindSize(); // ʳ������ �����
personnel* ReadInfo(int size); // ���������� ����������