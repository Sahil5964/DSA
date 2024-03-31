#include <bits/stdc++.h>
using namespace std;

int recursion(vector<int> &arr, int n)
{
    if (n == 1)
        return arr[0];
    if (n <= 0)
        return 0;

    return max(recursion(arr, n - 1), arr[n - 1] + recursion(arr, n - 2));
}

int memoization(vector<int> &arr, int n, vector<int> &dp)
{
    if (n == 1)
        return arr[0];
    if (n <= 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = max(memoization(arr, n - 1, dp), arr[n - 1] + memoization(arr, n - 2, dp));
}

int tabulization(vector<int> &arr, int n)
{
    if (n <= 0)
        return 0;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = arr[0];
    for (int i = 2; i <= n; i++)
        dp[i] = max(dp[i - 1], arr[i - 1] + dp[i - 2]);
    return dp[n];
}

int space_optimization(vector<int> &arr, int n)
{
    if (n <= 0)
        return 0;

    int prev2 = 0;
    int prev = arr[0];
    int cur;
    for (int i = 2; i <= n; i++)
    {
        cur = max(prev, arr[i - 1] + prev2);
        prev2 = prev;
        prev = cur;
    }

    return prev;
}

int main()
{
    vector<int> arr = {2, 1, 4, 9};
    vector<int> temp1(arr.begin(), arr.end() - 1), temp2(arr.begin() + 1, arr.end());
    vector<int> dp(arr.size() + 1, -1);
    cout << max(space_optimization(temp1, 0), space_optimization(temp2, 0)) << endl;
    cout << max(space_optimization(temp1, 1), space_optimization(temp2, 1)) << endl;
    cout << max(space_optimization(temp1, 2), space_optimization(temp2, 2)) << endl;
    cout << max(space_optimization(temp1, 3), space_optimization(temp2, 3)) << endl;
    return 0;
}