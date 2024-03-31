#include <bits/stdc++.h>
using namespace std;

int recursion(int n)
{
    if (n <= 1)
        return n;
    return recursion(n - 1) + recursion(n - 2);
}

int memoization(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = memoization(n - 1, dp) + memoization(n - 2, dp);
}

int tabulization(int n, vector<int> &dp)
{
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

int space_optimization(int n)
{
    int prev2 = 0;
    int prev = 1;
    int cur = 0;
    for (int i = 2; i <= n; ++i)
    {
        cur = prev + prev2;
        prev2 = prev;
        prev = cur;
    }

    return prev;
}

int main()
{
    int n = 100;
    vector<int> dp(n + 1, -1);
    cout << space_optimization(5) << endl;
    cout << space_optimization(6) << endl;
    cout << space_optimization(7) << endl;
    cout << space_optimization(8) << endl;
    cout << space_optimization(9) << endl;
    cout << space_optimization(19) << endl;
    return 0;
}