#include <bits/stdc++.h>
using namespace std;

bool isPossible(int N, vector<pair<int, int>> &prerequisites)
{
    vector<int> adj[N];
    vector<int> inDegree(N, 0);

    for (auto it : prerequisites)
    {
        inDegree[it.first]++;
        adj[it.second].push_back(it.first);
    }

    int count = 0;
    queue<int> Q;

    for (int i = 0; i < N; i++)
        if (!inDegree[i])
            Q.push(i);

    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        count++;
        for (auto e : adj[x])
        {
            inDegree[e]--;
            if (!inDegree[e])
                Q.push(e);
        }
    }

    return (count == N ? true : false);
}