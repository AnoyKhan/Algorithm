// 2D_Array_Operations.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(time(0));
    int N;
    cout << "Enter the size of the square matrix (N x N): ";
    cin >> N;
    int matrix[N][N];
    cout << "\nGenerated Matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 50 + 1;
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    int mainDiagonalSum = 0;
    for (int i = 0; i < N; i++) {
        mainDiagonalSum += matrix[i][i];
    }
    int antiDiagonalSum = 0;
    for (int i = 0; i < N; i++) {
        antiDiagonalSum += matrix[i][N - 1 - i];
    }
    cout << "\nSum of Main Diagonal Elements: " << mainDiagonalSum << endl;
    cout << "Sum of Anti-Diagonal Elements: " << antiDiagonalSum << endl;
    return 0;
}
