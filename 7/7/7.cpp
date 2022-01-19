#include <ctime>
#include <iostream>
using namespace std;
int** GenerateMatrix(int n, int m);
void MatrixOutput(int** M, int n, int m);
int** ChangeMatrix(int** M, int n, int m);
int** ToMirror(int** M, int n, int m);

int main()
{
    int n, m;
    int** M;
    cout << "n = ";
    cin >> n;
    if (n % 2 == 0) {
        exit(0);
    }
    cout << "m = ";
    cin >> m;
    cout << endl;
    M = GenerateMatrix(n, m);
    MatrixOutput(M, n, m);
    M = ChangeMatrix(M, n, m);
    MatrixOutput(M, n, m);
    M = ToMirror(M, n, m);
    MatrixOutput(M, n, m);
}

int** GenerateMatrix(int n, int m)
{
    srand((unsigned int)time(NULL));
    int** Matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        Matrix[i] = new int [m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Matrix[i][j] = rand() % 2;
        }
    }
    return Matrix;
}

void MatrixOutput(int** M, int n, int m)
{
    cout << endl;
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int** ChangeMatrix(int** M, int n, int m)
{
    int column = 0;;
    int max = 0;
    int counter;
    for (int j = 0; j < m; j++) {
        counter = 0;
        for (int i = 0; i < n; i++) {
            if (M[i][j] == 0) {
                counter++;
            }
        }
        if (counter > max) {
            max = counter;
            column = j;
        }
    }
    cout << "\n" << column + 1 << "\n";
    for (int i = 0; i < n; i++) {
        cout << M[i][column] << " ";
    }
    for (int i = 0; i < n; i++) {
        M[i][column] = i - column;
    }
    return M;
}

int** ToMirror(int** M, int n, int m)
{
    int** NewM = new int* [n];
    for (int i = 0; i < n; i++) {
        NewM[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == n / 2) {
                NewM[i][j] = M[i][j];
            }
            else {
                NewM[i][j] = M[n - i - 1][j];
            }
        }
    }
    return NewM;
}
