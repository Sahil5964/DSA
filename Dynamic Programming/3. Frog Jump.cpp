#include <bits/stdc++.h>
using namespace std;

int min_energy(vector<int> &energy, int n)
{
    if (n == 1)
        return 0;
    if (n < 1)
        return 1e5;
    int left = (n > 1) ? min_energy(energy, n - 1) + abs(energy[n - 1] - energy[n - 2]) : 1e5;
    int right = (n > 2) ? min_energy(energy, n - 2) + abs(energy[n - 1] - energy[n - 3]) : 1e5;
    return min(left, right);
}

int memo_energy(vector<int> &energy, int n, vector<int> &dp)
{
    if (n == 1)
        return 0;
    if (n < 1)
        return 1e5;
    if (dp[n] != -1)
        return dp[n];
    int left = (n > 1) ? memo_energy(energy, n - 1, dp) + abs(energy[n - 1] - energy[n - 2]) : 1e5;
    int right = (n > 2) ? memo_energy(energy, n - 2, dp) + abs(energy[n - 1] - energy[n - 3]) : 1e5;
    return dp[n] = min(left, right);
}

int tabulate_energy(vector<int> &energy, int n)
{
    if (n == 1)
        return 0;
    if (n < 1)
        return 1e5;

    vector<int> dp(energy.size() + 1);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = abs(energy[1] - energy[0]);
    int left = 0, right = 0;
    for (int i = 3; i <= n; i++)
    {
        int left = dp[i - 1] + abs(energy[i - 1] - energy[i - 2]);
        int right = dp[i - 2] + abs(energy[i - 1] - energy[i - 3]);
        dp[i] = min(left, right);
    }
    return dp[n];
}

int space_optimized_energy(vector<int> &energy, int n)
{
    if (n == 1)
        return 0;
    if (n < 1)
        return 1e5;

    int prev2 = 0;
    int prev = abs(energy[1] - energy[0]);
    int cur;
    int left = 0, right = 0;
    for (int i = 3; i <= n; i++)
    {
        int left = prev + abs(energy[i - 1] - energy[i - 2]);
        int right = prev2 + abs(energy[i - 1] - energy[i - 3]);
        cur = min(left, right);
        prev2 = prev;
        prev = cur;
    }

    return prev;
}

int main()
{
    vector<int> energy = {30, 10, 60, 10, 60, 50};
    vector<int> dp(energy.size() + 1, -1);
    cout << space_optimized_energy(energy, 0) << endl;
    cout << space_optimized_energy(energy, 1) << endl;
    cout << space_optimized_energy(energy, 2) << endl;
    cout << space_optimized_energy(energy, 3) << endl;
    cout << space_optimized_energy(energy, 4) << endl;
    cout << space_optimized_energy(energy, 5) << endl;
    cout << space_optimized_energy(energy, 6) << endl;
    return 0;
}