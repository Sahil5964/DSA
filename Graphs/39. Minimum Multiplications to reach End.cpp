#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int> &arr, int start, int end)
{
    vector<bool> nodes(100006, false);
    queue<pair<int, int>> Q;

    Q.push({0, start});
    nodes[start] = true;
    while (!Q.empty())
    {
        int count = Q.front().first;
        int node = Q.front().second;
        Q.pop();

        for (auto it : arr)
        {
            int newNode = (node * it) % 100000;

            if (newNode == end)
                return count + 1;

            if (!nodes[newNode])
            {
                nodes[newNode] = true;
                Q.push({count + 1, newNode});
            }
        }
    }

    return -1;
}