#include <iostream>
#include <vector>
using namespace std;

int recursion(vector<int> arr, int idx = 0, int prev = -1)
{
    if (idx == arr.size()) return 0;
    if (prev == -1 || arr[prev] < arr[idx])
        return max(1 + recursion(arr, idx + 1, idx), recursion(arr, idx + 1, prev));
    return recursion(arr, idx + 1, prev);
}

int memoization(vector<int> arr, vector<vector<int>> &dp, int idx = 0, int prev = -1)
{
    if (idx == arr.size()) return 0;
    if (dp[idx][prev + 1] != -1) return dp[idx][prev + 1];
    if (prev == -1 || arr[prev] < arr[idx])
        return dp[idx][prev + 1] = max(1 + memoization(arr, dp, idx + 1, idx), memoization(arr, dp, idx + 1, prev));
    return dp[idx][prev + 1] = memoization(arr, dp, idx + 1, prev);
}

int tabulization(vector<int> arr, int x, int y)
{
    
}

// int space_optimization(vector<int> arr, int x, int y)
// {
// }

int main()
{
    vector<int> arr = { 10, 9, 2, 5, 3, 7, 101, 18 };
    vector<vector<int>> dp (200, vector<int> (200, -1));
    cout << memoization(arr, dp) << endl;;
    return 0;
}