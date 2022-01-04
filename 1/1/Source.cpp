#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "header.h"
using namespace std;

int** CreateMatrix(int MatrixSize)
{
	int** Matrix = new int* [MatrixSize];
	for (int i = 0; i < MatrixSize; i++) {
		Matrix[i] = new int[MatrixSize];
	}
	return Matrix;
}

int** GenerateAElements(int** Matrix, int MatrixSize)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < MatrixSize; i++) {
		for (int j = 0; j < MatrixSize; j++) {
			Matrix[i][j] = rand() % 19 - 9;

		}
	}
	return Matrix;
}

void MatrixOutput(int** Matrix, int MatrixSize)
{
	cout << "\n";
	for (int i = 0; i < MatrixSize; i++) {
		for (int j = 0; j < MatrixSize; j++) {
			if (Matrix[i][j] < 0) {
				cout << Matrix[i][j] << "  ";
			}
			else {
				cout << " " << Matrix[i][j] << "  ";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

int** ToMirror(int** Matrix, int** MirroredMatrix, int MatrixSize)
{
	int i, j;
	for (i = 0; i < MatrixSize; i++) {
		for (j = 0; j < MatrixSize; j++) {
			MirroredMatrix[i][j] = Matrix[j][i];
		}
	}
	return MirroredMatrix;
}

int** DeleteColumn(int** MirroredMatrix, int ColumnToDelete, int MatrixSize)
{
	int** NewMatrix = new int* [MatrixSize];
	for (int i = 0; i < MatrixSize; i++) {
		NewMatrix[i] = new int[MatrixSize - 1];
		int pos = 0;
		for (int j = 0; j < MatrixSize; j++) {
			if (j != ColumnToDelete - 1) {
				NewMatrix[i][pos] = MirroredMatrix[i][j];
				pos++;
			}
		}
	}
	return NewMatrix;
}

void NewMatrixOutput(int** Matrix, int MatrixSize)
{
	cout << "\n";
	for (int i = 0; i < MatrixSize; i++) {
		for (int j = 0; j < MatrixSize - 1; j++) {
			if (Matrix[i][j] < 0) {
				cout << Matrix[i][j] << "  ";
			}
			else {
				cout << " " << Matrix[i][j] << "  ";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

string* MakeString(int** NewMatrix, int MatrixSize)
{
	string* str = new string[MatrixSize];
	for (int i = 0; i < MatrixSize; i++) {
		for (int j = 0; j < MatrixSize - 2; j++) {
			str[i] += to_string(NewMatrix[i][j] - NewMatrix[i][j + 1]) + ' ';
		}
	}
	return str;
}

void OutputString(string* str, int MatrixSize)
{
	for (int i = 0; i < MatrixSize; i++) {
		cout << str[i] << endl;
	}
}

string* MakeNewString(int** NewMatrix, int MatrixSize)
{
	string* str = new string[MatrixSize];
	for (int i = 0; i < MatrixSize; i++) {
		for (int j = 0; j < MatrixSize - 2; j++) {
			if (NewMatrix[i][j] - NewMatrix[i][j + 1] < 0) {
				str[i] += to_string(NewMatrix[i][j] - NewMatrix[i][j + 1]) + ' ';
			}
		}
	}

	for (int i = 0; i < MatrixSize; i++) {
		for (int j = 0; j < MatrixSize - 2; j++) {
			if (NewMatrix[i][j] - NewMatrix[i][j + 1] >= 0) {
				str[i] += to_string(NewMatrix[i][j] - NewMatrix[i][j + 1]) + ' ';
			}
		}
	}
	return str;
}

string* SortNewString(string* NewStr, int MatrixSize)
{
	int i = 0, j;
	string tmp;
	while (i < MatrixSize - 1) {
		int j = 0;
		while (j < MatrixSize - 1 - i) {
			if (NewStr[j + 1].length() < NewStr[j].length()) {
				tmp = NewStr[j];
				NewStr[j] = NewStr[j + 1];
				NewStr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return NewStr;
}