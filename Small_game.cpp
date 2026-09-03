#include <iostream>
using namespace std;

int main()
{
    int grid[3][3] =
    {
        {1, 0, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    int liveEnemies = 0;
    int hits = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] == 1)
            {
                liveEnemies++;
            }
        }
    }
    cout << "Total live enemies: " << liveEnemies << endl;
    cout << endl;
    while (liveEnemies > 0)
    {
        int row, column;
        cout << "Enter row and column (0-2): ";
        cin >> row >> column;
        if (grid[row][column] == 1)
        {
            grid[row][column] = 0;
            liveEnemies--;
            hits++;

            cout << "Hit. Enemy destroyed." << endl;
        }
        else
        {
            cout << "No live enemy at this position." << endl;
        }
        cout << endl;
    }
    cout << "All enemies are destroyed." << endl;
    cout << "Total hits required: " << hits << endl;
    cout << endl;
    cout << "Final Grid:" << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

