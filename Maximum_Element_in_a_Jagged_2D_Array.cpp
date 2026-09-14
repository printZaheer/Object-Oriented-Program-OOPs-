#include <iostream>
using namespace std;

int findMax(int **arr, int rows, int *colCounts) {
    int maxVal = arr[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colCounts[i]; j++) {
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j];
            }
        }
    }
    return maxVal;
}
int main() {
    int rows = 3;
    int colCounts[3] = {2, 5, 3};
    int **jagged = new int*[rows];
    for (int i = 0; i < rows; i++) {
        jagged[i] = new int[colCounts[i]];
    }
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colCounts[i]; j++) {
            jagged[i][j] = value++;
        }
    }
    jagged[1][3] = 100;
    cout << "Jagged array:" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < colCounts[i]; j++) {
            cout << jagged[i][j] << " ";
        }
        cout << endl;
    }
    int maxVal = findMax(jagged, rows, colCounts);
    cout << "\nMaximum element: " << maxVal << endl;
    for (int i = 0; i < rows; i++) {
        delete[] jagged[i];
    }
    delete[] jagged;

    return 0;
}
