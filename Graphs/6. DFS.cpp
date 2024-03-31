#include <bits/stdc++.h>
using namespace std;

void dfsHelper(int source, vector<int> adj[], vector<bool> &visited, vector<int> &dfs)
{
    visited[source] = true;
    dfs.push_back(source);

    for (auto x : adj[source])
    {
        if (!visited[x])
            dfsHelper(x, adj, visited, dfs);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> dfs;
    vector<bool> visited(V, false);

    dfsHelper(0, adj, visited, dfs);

    return dfs;
}