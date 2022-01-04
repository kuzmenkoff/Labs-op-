#include <iostream>
#include <ctime>
using namespace std;

int** CreateMatrix(int MatrixSize);
int** FindSpecialElement(int** Matrix, int MatrixSize);
bool IsSpecial(int** Matrix, int j, int i);

int main()
{
    int** Matrix;
    int** NewMatrix;
    int MatrixSize;
    cout << "Enter size:";
    cin >> MatrixSize;
    if (MatrixSize % 2 == 0) {
        return;
    }
    Matrix = CreateMatrix(MatrixSize);
    NewMatrix = FindSpecialElement(Matrix, MatrixSize);

}

int** CreateMatrix(int MatrixSize)
{
    int** Matrix = new int* [MatrixSize];
    for (int i = 0; i < MatrixSize; i++) {
        Matrix[i] = new int[MatrixSize];
    }

    srand((unsigned int)time(NULL));

    for (int i = 0; i < MatrixSize; i++) {
        for (int j = 0; j < MatrixSize; j++) {
            Matrix[i][j] = rand() % (900 + 1 + 150) - 150;

        }
    }
    return Matrix;
}

int** FindSpecialElement(int** Matrix, int MatrixSize)
{
    int i = 0;  
    int y = MatrixSize;
    int x = 0;
    int j;
    do {
        do {
            j = x;
            if (IsSpecial(Matrix, j, i)) {
                

            }
            j++;

        } while (j < y || IsSpecial(Matrix, j, i));

        x++;
        y--;
    } while (i < (MatrixSize + 1) / 2 || IsSpecial(Matrix, j, i));

  
}

bool IsSpecial(int** Matrix, int j, int i)
{
    if (Matrix[i][j] < (abs(Matrix[i][j + 1] + abs(Matrix[i][j - 1])) {
        return true;
    }
    else {
        return false;
    }
}