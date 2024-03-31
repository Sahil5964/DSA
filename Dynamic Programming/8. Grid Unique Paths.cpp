#include <bits/stdc++.h>
using namespace std;

int recursion(int x, int y)
{
    if (x == 1 && y == 1)
        return 1;
    if (x < 1 || y < 1)
        return 0;
    return recursion(x - 1, y) + recursion(x, y - 1);
}

int memoization(int x, int y, vector<vector<int>> &dp)
{
    if (x == 1 && y == 1)
        return 1;
    if (x < 1 || y < 1)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    return dp[x][y] = memoization(x - 1, y, dp) + memoization(x, y - 1, dp);
}

int tabulization(int x, int y)
{
    vector<vector<int>> dp(10, vector<int>(10, 0));
    dp[1][1] = 1;
    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= y; j++)
            if (i != 1 || j != 1)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    return dp[x][y];
}

int space_optimization(int x, int y)
{
    vector<int> prev(10, 0);
    vector<int> temp(10, 0);
    prev[1] = 1;
    temp[1] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
            if (i != 1 || j != 1)
                temp[j] = prev[j] + temp[j - 1];
        prev = temp;
    }
    return prev[y];
}

// ----------------------------------------------------------------/
// This solution based on the combination problem:
// only possible moves are R (right) or D (down)
// Path length is also always, fixed => (n - 1) + (m - 1)
// So, basically find number of ways to place R and D in n + m - 2.
// ----------------------------------------------------------------/
int linear(int x, int y)
{
    int total = x + y - 2;
    int remain = x - 1;
    int res = 1;

    for (int i = 1; i <= remain; i++)
        res = res * ((total - remain + i) / i);
    return (int)res;
}

int main()
{
    vector<vector<int>> dp(10, vector<int>(10, -1));
    cout << linear(2, 2) << endl;
    cout << linear(1, 2) << endl;
    cout << linear(2, 3) << endl;
    cout << linear(2, 4) << endl;
    cout << linear(3, 3) << endl;
    return 0;
}