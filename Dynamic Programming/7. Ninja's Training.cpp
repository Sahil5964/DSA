#include <bits/stdc++.h>
using namespace std;

int recursion(vector<vector<int>> &arr, int n, int lastTask)
{
    if (n == 1)
        return max({lastTask == 0 ? INT_MIN : arr[0][0], lastTask == 1 ? INT_MIN : arr[0][1], lastTask == 2 ? INT_MIN : arr[0][2]});
    if (n <= 0)
        return 0;

    int task1 = lastTask == 0 ? INT_MIN : arr[n - 1][0] + recursion(arr, n - 1, 0);
    int task2 = lastTask == 1 ? INT_MIN : arr[n - 1][1] + recursion(arr, n - 1, 1);
    int task3 = lastTask == 2 ? INT_MIN : arr[n - 1][2] + recursion(arr, n - 1, 2);
    return max({task1, task2, task3});
}

// There may be problem with this memoization.
// This may not be solve using 1D DP.
// Alternative, make dp[day][task] instead of dp[day]
int memoization(vector<vector<int>> &arr, int n, int lastTask, vector<int> &dp)
{
    if (n == 1)
        return dp[1] = max({lastTask == 0 ? INT_MIN : arr[0][0], lastTask == 1 ? INT_MIN : arr[0][1], lastTask == 2 ? INT_MIN : arr[0][2]});
    if (n <= 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int task1 = lastTask == 0 ? INT_MIN : arr[n - 1][0] + memoization(arr, n - 1, 0, dp);
    int task2 = lastTask == 1 ? INT_MIN : arr[n - 1][1] + memoization(arr, n - 1, 1, dp);
    int task3 = lastTask == 2 ? INT_MIN : arr[n - 1][2] + memoization(arr, n - 1, 2, dp);
    return dp[n] = max({task1, task2, task3});
}

// May be problem in storing values in dp, it may be possible to use dp[1][x] store max of other than x.
// Only, issue in the initialization case.
int tabulation(vector<vector<int>> &arr, int n)
{
    if (n <= 0)
        return 0;
    vector<vector<int>> dp(n + 1, vector<int>(3));
    dp[1][0] = arr[0][0];
    dp[1][1] = arr[0][1];
    dp[1][2] = arr[0][2];

    for (int i = 2; i <= n; i++)
        for (int j = 0; j < 3; j++)
            dp[i][j] = arr[i - 1][j] + max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);

    return max({dp[n][0], dp[n][1], dp[n][2]});
}

// May be problem in storing values in dp, it may be possible to use dp[1][x] store max of other than x.
// Only, issue in the initialization case.
int space_optimization(vector<vector<int>> &arr, int n)
{
    if (n <= 0)
        return 0;
    vector<vector<int>> dp(2, vector<int>(3));
    dp[1][0] = arr[0][0];
    dp[1][1] = arr[0][1];
    dp[1][2] = arr[0][2];

    for (int i = 2; i <= n; i++)
        for (int j = 0; j < 3; j++)
            dp[i % 2][j] = arr[i - 1][j] + max(dp[(i - 1) % 2][(j + 1) % 3], dp[(i - 1) % 2][(j + 2) % 3]);

    return max({dp[n % 2][0], dp[n % 2][1], dp[n % 2][2]});
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    // vector<vector<int>> arr = {{10, 50, 1}, {5, 100, 11}};
    vector<int> dp(arr.size() + 1, -1);
    cout << space_optimization(arr, 0) << endl;
    cout << space_optimization(arr, 1) << endl;
    cout << space_optimization(arr, 2) << endl;
    cout << space_optimization(arr, 3) << endl;
    return 0;
}