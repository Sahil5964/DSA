#include <bits/stdc++.h>
using namespace std;

int recursion(vector<vector<int>> arr, int x, int y)
{
    if (x == 1 && y == 1)
        return 1;
    if (x < 1 || y < 1 || arr[x - 1][y - 1] == -1)
        return 0;
    return recursion(arr, x - 1, y) + recursion(arr, x, y - 1);
}

int memoization(vector<vector<int>> arr, int x, int y, vector<vector<int>> &dp)
{
    if (x == 1 && y == 1)
        return 1;
    if (x < 1 || y < 1 || arr[x - 1][y - 1] == -1)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    return dp[x][y] = memoization(arr, x - 1, y, dp) + memoization(arr, x, y - 1, dp);
}

int tabulization(vector<vector<int>> arr, int x, int y)
{
    vector<vector<int>> dp(10, vector<int>(10, 0));
    dp[1][1] = 1;
    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= y; j++)
            if (arr[i - 1][j - 1] == -1)
                dp[i][j] = 0;
            else if (i != 1 || j != 1)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    return dp[x][y];
}

int space_optimization(vector<vector<int>> arr, int x, int y)
{
    vector<int> prev(10, 0);
    vector<int> temp(10, 0);
    prev[1] = 1;
    temp[1] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
            if (arr[i - 1][j - 1] == -1)
                temp[j] = 0;
            else if (i != 1 || j != 1)
                temp[j] = prev[j] + temp[j - 1];
        prev = temp;
    }
    return prev[y];
}

int main()
{
    vector<vector<int>> arr = {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};
    vector<vector<int>> dp(10, vector<int>(10, -1));
    cout << recursion(arr, 3, 3) << endl;
    cout << memoization(arr, 3, 3, dp) << endl;
    cout << tabulization(arr, 3, 3) << endl;
    cout << space_optimization(arr, 3, 3) << endl;
    return 0;
}