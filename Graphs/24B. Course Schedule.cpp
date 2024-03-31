#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites)
{
    vector<int> ans;
    vector<int> adj[n];
    vector<int> inDegree(n, 0);

    for (auto it : prerequisites)
    {
        inDegree[it[0]]++;
        adj[it[1]].push_back(it[0]);
    }

    int count = 0;
    queue<int> Q;

    for (int i = 0; i < n; i++)
        if (!inDegree[i])
            Q.push(i);

    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        count++;
        ans.push_back(x);
        for (auto e : adj[x])
        {
            inDegree[e]--;
            if (!inDegree[e])
                Q.push(e);
        }
    }

    return (count == n ? ans : vector<int>{});
}