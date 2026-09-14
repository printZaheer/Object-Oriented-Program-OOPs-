#include <iostream>
using namespace std;

int* rowSums(int **matrix, int rows, int cols) {
    int *sums = new int[rows];

    for (int i = 0; i < rows; i++) {
        sums[i] = 0;
        for (int j = 0; j < cols; j++) {
            sums[i] += matrix[i][j];
        }
    }
    return sums;
}

int main() {
    int rows = 3, cols = 4;
    int **matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value++;
        }
    }
    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    int *sums = rowSums(matrix, rows, cols);

    cout << "\nRow sums:" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i << ": " << sums[i] << endl;
    }
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] sums;

    return 0;
}
