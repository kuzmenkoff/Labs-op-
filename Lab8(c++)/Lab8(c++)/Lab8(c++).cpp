#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void MatrixOutput(int** Matrix, int MatrixSize); // Вивід матриці
int** CreateMatrix(int MatrixSize); // Задає розмір
int** GenerateAElements(int** Matrix, int MatrixSize); // Генерація матриці А випадковим чином
int** GenerateBElements(int** AMatrix, int** BMatrix, int MatrixSize); // Генерація матриці В відповідно умові

int main()
{
	setlocale(LC_ALL, "Russian");
	int MatrixSize;
	int** AMatrix;
	int** BMatrix;
	cout << "Введите размер квадратной матрицы А:" << endl;
	cin >> MatrixSize;
	AMatrix = CreateMatrix(MatrixSize);
	AMatrix = GenerateAElements(AMatrix, MatrixSize);
	BMatrix = CreateMatrix(MatrixSize);
	BMatrix = GenerateBElements(AMatrix, BMatrix, MatrixSize);
	MatrixOutput(AMatrix, MatrixSize);
	MatrixOutput(BMatrix, MatrixSize);
}

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
			Matrix[i][j] = rand() % 90 + 10;

		}
	}
	return Matrix;
}

int** GenerateBElements(int** AMatrix, int** BMatrix, int MatrixSize)
{
	int DiagMin, TriangleMin, i, j, x, y;
	for (i = 0; i < MatrixSize; i++) {
		for (j = 0; j < MatrixSize; j++) {
			DiagMin = AMatrix[j][j];
			for (x = i; x <= j; x++) {
				if (AMatrix[x][x] < DiagMin) {
					DiagMin = AMatrix[x][x];
				}
			}
			if (i == j) {
				BMatrix[i][j] = AMatrix[i][j];

			}
			else if (i < j) {
				DiagMin = AMatrix[j][j];
				for (x = i; x <= j; x++) {
					if (AMatrix[x][x] < DiagMin) {
						DiagMin = AMatrix[x][x];
					}
				}
				x = i;
				y = j;
				TriangleMin = AMatrix[i][j];
				while (x != j) {
					x++;
					if (AMatrix[x][y] < TriangleMin) {
						TriangleMin = AMatrix[x][y];
					}
				}
				x = i;
				while (y != i) {
					y--;
					if (AMatrix[x][y] < TriangleMin) {
						TriangleMin = AMatrix[x][y];
					}
				}
				if (TriangleMin < DiagMin) {
					BMatrix[i][j] = TriangleMin;
				}
				else {
					BMatrix[i][j] = DiagMin;
				}

			}
			else if (i > j) {
				DiagMin = AMatrix[i][i];
				for (x = j; x <= i; x++) {
					if (AMatrix[x][x] < DiagMin) {
						DiagMin = AMatrix[x][x];
					}
				}
				x = i;
				y = j;
				TriangleMin = AMatrix[i][j];
				while (x != j) {
					x--;
					if (AMatrix[x][y] < TriangleMin) {
						TriangleMin = AMatrix[x][y];
					}
				}
				x = i;
				while (y != i) {
					y++;
					if (AMatrix[x][y] < TriangleMin) {
						TriangleMin = AMatrix[x][y];
					}
				}
				if (TriangleMin < DiagMin) {
					BMatrix[i][j] = TriangleMin;
				}
				else {
					BMatrix[i][j] = DiagMin;
				}

			}
		}
	}
	return BMatrix;
}

void MatrixOutput(int** Matrix, int MatrixSize)
{
	for (int i = 0; i < MatrixSize; i++) {
		for (int j = 0; j < MatrixSize; j++) {
			cout << Matrix[i][j] << "  ";
		}
		cout << " " << endl;
	}
	cout << "\n";
}

