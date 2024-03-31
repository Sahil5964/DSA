#include <bits/stdc++.h>
using namespace std;

int recursion(vector<vector<int>> arr, int x, int y)
{
    if (x == 1 && y == 1)
        return arr[0][0];
    if (x < 1 || y < 1)
        return 1e5;
    return arr[x - 1][y - 1] + min(recursion(arr, x - 1, y), recursion(arr, x, y - 1));
}

int memoization(vector<vector<int>> arr, int x, int y, vector<vector<int>> &dp)
{
    if (x == 1 && y == 1)
        return arr[0][0];
    if (x < 1 || y < 1)
        return 1e5;
    if (dp[x][y] != -1)
        return dp[x][y];
    return dp[x][y] = arr[x - 1][y - 1] + min(memoization(arr, x - 1, y, dp), memoization(arr, x, y - 1, dp));
}

int tabulization(vector<vector<int>> arr, int x, int y)
{
    vector<vector<int>> dp(10, vector<int>(10, 1e5));
    dp[1][1] = arr[0][0];
    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= y; j++)
            if (i != 1 || j != 1)
                dp[i][j] = arr[i - 1][j - 1] + min(dp[i - 1][j], dp[i][j - 1]);
    return dp[x][y];
}

int space_optimization(vector<vector<int>> arr, int x, int y)
{
    vector<int> prev(10, 1e5);
    vector<int> temp(10, 1e5);
    prev[1] = arr[0][0];
    temp[1] = arr[0][0];
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
            if (i != 1 || j != 1)
                temp[j] = arr[i - 1][j - 1] + min(prev[j], temp[j - 1]);
        prev = temp;
    }
    return prev[y];
}

int main()
{
    vector<vector<int>> arr = {{5, 9, 6}, {11, 5, 2}};
    vector<vector<int>> dp(10, vector<int>(10, -1));
    cout << recursion(arr, 2, 3) << endl;
    cout << memoization(arr, 2, 3, dp) << endl;
    cout << tabulization(arr, 2, 3) << endl;
    cout << space_optimization(arr, 2, 3) << endl;
    return 0;
}