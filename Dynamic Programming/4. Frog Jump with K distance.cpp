#include <bits/stdc++.h>
using namespace std;

int min_energy(vector<int> &energy, int n, int k)
{
    if (n == 1)
        return 0;
    if (n < 1)
        return 1e5;

    int ans = 1e5;
    for (int i = 1; i <= k; i++)
        if (n - i - 1 >= 0)
            ans = min(ans, min_energy(energy, n - i, k) + abs(energy[n - 1] - energy[n - i - 1]));

    return ans;
}

int memo_energy(vector<int> &energy, int n, int k, vector<int> &dp)
{
    if (n == 1)
        return 0;
    if (n < 1)
        return 1e5;
    if (dp[n] != -1)
        return dp[n];

    int ans = 1e5;
    for (int i = 1; i <= k; i++)
        if (n - i - 1 >= 0)
            ans = min(ans, min_energy(energy, n - i, k) + abs(energy[n - 1] - energy[n - i - 1]));

    return dp[n] = ans;
}

int tabulate_energy(vector<int> &energy, int n, int k)
{
    if (n < 1)
        return 1e5;

    vector<int> dp(n + 1, INT_MAX);
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i && j <= k; j++)
            dp[i] = min(dp[i], dp[i - j] + abs(energy[i - 1] - energy[i - j - 1]));

    return dp[n];
}

int space_optimized_energy(vector<int> &energy, int n, int k)
{
    if (n < 1)
        return 1e5;

    vector<int> dp(k + 1, INT_MAX);
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i % (k + 1)] = INT_MAX;
        for (int j = 1; j < i && j <= k; j++)
            dp[i % (k + 1)] = min(dp[i % (k + 1)], dp[(i - j) % (k + 1)] + abs(energy[i - 1] - energy[i - j - 1]));
    }

    return dp[n % (k + 1)];
}

int main()
{
    vector<int> energy = {30, 10, 60, 10, 60, 50};
    int k = 4;
    vector<int> dp(energy.size() + 1, -1);
    cout << tabulate_energy(energy, 0, k) << endl;
    cout << tabulate_energy(energy, 1, k) << endl;
    cout << tabulate_energy(energy, 2, k) << endl;
    cout << tabulate_energy(energy, 3, k) << endl;
    cout << tabulate_energy(energy, 4, k) << endl;
    cout << tabulate_energy(energy, 5, k) << endl;
    cout << tabulate_energy(energy, 6, k) << endl;
    return 0;
}