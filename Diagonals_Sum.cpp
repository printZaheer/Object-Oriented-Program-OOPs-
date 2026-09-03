#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter the size of matrix: ";
    cin >> size;
    int matrix[100][100];
    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + matrix[i][i];

        if (i != size - 1 - i)
        {
            sum = sum + matrix[i][size - 1 - i];
        }
    }
    cout << "Sum of Diagonals = " << sum << endl;
    return 0;
}

