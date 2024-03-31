#include <bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    vector<int> safeNodes;
    vector<int> revAdj[V];

    for (int i = 0; i < V; i++)
        for (auto e : adj[i])
            revAdj[e].push_back(i);

    queue<int> Q;
    vector<int> inDegree(V, 0);

    for (int i = 0; i < V; i++)
        for (auto it : revAdj[i])
            inDegree[it]++;

    for (int i = 0; i < V; i++)
        if (!inDegree[i])
            Q.push(i);

    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        safeNodes.push_back(x);

        for (auto e : revAdj[x])
        {
            inDegree[e]--;
            if (!inDegree[e])
                Q.push(e);
        }
    }

    sort(safeNodes.begin(), safeNodes.end());

    return safeNodes;
}