#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "header.h"
using namespace std;


int main()
{
	int** Matrix;
	int** MirroredMatrix;
	int** NewMatrix;
	int MatrixSize, ColumnToDelete;
	string* str;
	string* NewStr;
	//========= 1 ================
	cout << "Enter size:" << endl;
	cin >> MatrixSize;
	Matrix = CreateMatrix(MatrixSize);
	Matrix = GenerateAElements(Matrix, MatrixSize);
	cout << "\nCreated matrix:\n";
	MatrixOutput(Matrix, MatrixSize);
	//========= 2 ================
	MirroredMatrix = CreateMatrix(MatrixSize);
	MirroredMatrix = ToMirror(Matrix, MirroredMatrix, MatrixSize);
	cout << "Mirrored matrix:\n";
	MatrixOutput(MirroredMatrix, MatrixSize);
	//========= 3 ================
	cout << "Enter the number of column you want to delete:" << endl;
	cin >> ColumnToDelete;
	NewMatrix = DeleteColumn(MirroredMatrix, ColumnToDelete, MatrixSize);
	cout << "\nMirrored Matrix with deleted column:\n";
	NewMatrixOutput(NewMatrix, MatrixSize);
	//========= 4 ================
	cout << "\nString of differences:\n";
	str = MakeString(NewMatrix, MatrixSize);
	OutputString(str, MatrixSize);
	//========= 5 ================
	cout << "\nNew string of differences:\n";
	NewStr = MakeNewString(NewMatrix, MatrixSize);
	OutputString(NewStr, MatrixSize);
	//========= 6 ================
	cout << "\nSorted new string of differences:\n";
	NewStr = SortNewString(NewStr, MatrixSize);
	OutputString(NewStr, MatrixSize);
}

