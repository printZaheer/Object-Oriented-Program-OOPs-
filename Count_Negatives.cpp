#include <iostream>
using namespace std;

int main()
{
    int rows, columns;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> columns;

    int grid[100][100];

    cout << "Enter the elements of the matrix:" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> grid[i][j];
        }
    }
    int count = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (grid[i][j] < 0)
            {
                count++;
            }
        }
    }
    cout << endl;
    cout << "Number of negative numbers = " << count << endl;

    return 0;
}

