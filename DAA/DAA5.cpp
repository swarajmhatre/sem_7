#include <iostream>
using namespace std;
bool isSafe(int **arr, int row, int col, int n)
{
    for (int i = 0; i < row; i++)
    {
        if (arr[i][col] == 1)
        {
            return false;
        }
    }
    int i = row;
    int j = col;
    while (i >= 0 && j >= 0)
    {
        if (arr[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }
    i = row;
    j = col;
    while (i >= 0 && j < n)
    {
        if (arr[i][j] == 1)
        {
            return false;
        }
        i--;
        j++;
    }
    return true;
}

void printBoard(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                cout << "[Q] ";
            }
            else
            {
                cout << "[ ] ";
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}
void NQueen(int **arr, int x, int n)
{
    if (x == n)
    {
        printBoard(arr, n);
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, x, col, n))
        {
            arr[x][col] = 1;
            NQueen(arr, x + 1, n);
            arr[x][col] = 0;
        }
    }
}
int main()
{
    int n;
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    NQueen(arr, 0, n);
    cout << "_______________HOGAYA________________";
    return 0;
}