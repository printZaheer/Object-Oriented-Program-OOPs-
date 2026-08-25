#include <iostream>
using namespace std;

const int SIZE = 3;
void inputMatrix(int mat[SIZE][SIZE]) {
    cout << "Enter 9 elements row-wise: ";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> mat[i][j];
        }
    }
}
void displayMatrix(int mat[SIZE][SIZE]) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
void rowSums(int mat[SIZE][SIZE]) {
    cout << "Row sums: ";
    for (int i = 0; i < SIZE; i++) {
        int sum = 0;
        for (int j = 0; j < SIZE; j++) {
            sum += mat[i][j];
        }
        cout << sum << " ";
    }
    cout << endl;
}
int main() {
    int mat[SIZE][SIZE];

    inputMatrix(mat);
    displayMatrix(mat);
    rowSums(mat);

    return 0;
}
