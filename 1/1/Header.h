#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

int** CreateMatrix(int MatrixSize);
int** GenerateAElements(int** Matrix, int MatrixSize);
void MatrixOutput(int** Matrix, int MatrixSize);
int** ToMirror(int** Matrix, int** MirroredMatrix, int MatrixSize);
int** DeleteColumn(int** MirroredMatrix, int ColumnToDelete, int MatrixSize);
void NewMatrixOutput(int** Matrix, int MatrixSize);
string* MakeString(int** NewMatrix, int MatrixSize);
void OutputString(string* str, int MatrixSize);
string* MakeNewString(int** NewMatrix, int MatrixSize);
string* SortNewString(string* NewStr, int MatrixSize);
