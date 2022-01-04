#include <cmath>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

char** GetStr(int StrNum);
int* MakeDecimal(char** Numbers, int StrNum);
int** CreateMatrix(int MatrixSize, int RandMin, int RandMax, int* DecNumbers);
void MatrixOutput(int** Matrix, int MatrixSize);
int** SortMatrix(int** Matrix, int MatrixSize);
int FindMaxModule(int* Row, int MatrixSize);

int main()
{
    int StrNum, RandMin, RandMax;
    //========= 1 ================
    cout << "Enter number of strings:" << endl;
    cin >> StrNum;
    cout << "\nEnter binary code:\n";
    char** Numbers = GetStr(StrNum);
    //========= 2 ================
    cout << "\nNumbers you've entered:\n";
    int* DecNumbers = MakeDecimal(Numbers, StrNum);
    //========= 3 ================
    cout << "\nEnter rand range:\n";
    cout << "Min = ";
    cin >> RandMin;
    cout << "Max = ";
    cin >> RandMax;
    int** Matrix = CreateMatrix(StrNum, RandMin, RandMax, DecNumbers);
    cout << "\nMatrix:\n";
    MatrixOutput(Matrix, StrNum);
    Matrix = SortMatrix(Matrix, StrNum);
    MatrixOutput(Matrix, StrNum);
}

char** GetStr(int StrNum)
{
    char** Numbers = new char* [StrNum];
    for (int i = 0; i < StrNum; ++i) {
        Numbers[i] = new char[100];
    }
    for (int i = 0; i < StrNum; ++i) {
        cin >> Numbers[i];
    }
    return Numbers;
}

int* MakeDecimal(char** Numbers, int StrNum)
{
    cout << "\n";
    int* Sum = new int[StrNum];
    for (int j = 0; j < StrNum; j++) {
        Sum[j] = 0;
        int size = strlen(Numbers[j]);
        _strrev(Numbers[j]);
        int* NumberArray = new int[size + 1];
        for (int i = 0; i < size; i++) {
            NumberArray[i] = Numbers[j][i] - 48;
        }

        for (int i = 0; i < size; i++) {
            Sum[j] += pow(2, i) * NumberArray[i];
        }

        cout << Sum[j] << " ";
    }
    cout << "\n";
    return Sum;

}

int** CreateMatrix(int MatrixSize, int RandMin, int RandMax, int* DecNumbers)
{
    srand((unsigned int)time(NULL));

    int** Matrix = new int* [MatrixSize];
    for (int i = 0; i < MatrixSize; i++) {
        Matrix[i] = new int[MatrixSize];
    }

    for (int i = 0; i < MatrixSize; i++) {
        for (int j = 0; j < MatrixSize; j++) {
            if (i == j) {
                Matrix[i][j] = DecNumbers[j];
            }
            else {
                Matrix[i][j] = rand() % (RandMax + 1 - RandMin) + RandMin;
            }
        }
    }
    return Matrix;
}

int** SortMatrix(int** Matrix, int MatrixSize)
{
    int i = 0;
    int* TmpRow = new int[MatrixSize];
    while (i < MatrixSize - 1) {
        int j = 0;
        while (j < MatrixSize - 1 - i) {
            if (FindMaxModule(Matrix[j], MatrixSize) < FindMaxModule(Matrix[j+1], MatrixSize)) {
                for (int y = 0; y < MatrixSize; y++) {
                    TmpRow[y] = Matrix[j][y];
                }
                for (int y = 0; y < MatrixSize; y++) {
                    Matrix[j][y] = Matrix[j + 1][y];
                }
                for (int y = 0; y < MatrixSize; y++) {
                    Matrix[j + 1][y] = TmpRow[y];
                }
            }
            j++;
        }
        i++;
    }
    return Matrix;
}

int FindMaxModule(int* Row, int MatrixSize)
{
    int MaxModule = abs(Row[0]);
    for (int i = 0; i < MatrixSize; i++) {
        if (abs(Row[i]) < abs(Row[i + 1])) {
            MaxModule = abs(Row[i + 1]);
        }
    }
    return MaxModule;
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
