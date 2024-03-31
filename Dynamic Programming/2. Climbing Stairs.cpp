#include <bits/stdc++.h>
using namespace std;

// Need Matrix Exponentiation as N <= 10^9
int count_ways(int n)
{
    int prev = 1;
    int prev2 = 1;
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
    cout << count_ways(0) << endl;
    cout << count_ways(1) << endl;
    cout << count_ways(2) << endl;
    cout << count_ways(3) << endl;
    cout << count_ways(4) << endl;
    cout << count_ways(5) << endl;
    return 0;
}