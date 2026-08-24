#include <iostream>
using namespace std;

void displayMatrix(int arr[][4], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    cout << "Matrix contents:" << endl;
    displayMatrix(matrix, 3, 4);

    return 0;
}