#include <bits/stdc++.h>
using namespace std;

bool dfs(int source, int parent, vector<int> adj[], vector<bool> &visited)
{
    visited[source] = true;

    for (auto x : adj[source])
    {
        if (!visited[x])
        {
            if (dfs(x, source, adj, visited))
                return true;
        }
        else if (x != parent)
            return true;
    }

    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dfs(i, -1, adj, visited))
            return true;
    }

    return false;
}