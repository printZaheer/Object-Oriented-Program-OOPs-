#include <iostream>
using namespace std;

int main()
{
    int m, n;

    cout << "Enter number of rows (m): ";
    cin >> m;

    cout << "Enter number of columns (n): ";
    cin >> n;

    int size = m * n;
    int original[100];
    
    cout << "Enter " << size << " elements:" << endl;

    for (int i = 0; i < size; i++)
    {
        cin >> original[i];
    }

    int result[100][100];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = original[i * n + j];
        }
    }
    cout << endl;
    cout << "2D Array:" << endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}




