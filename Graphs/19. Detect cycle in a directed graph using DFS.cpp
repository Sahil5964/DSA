#include <bits/stdc++.h>
using namespace std;

bool dfs(int source, vector<int> adj[], vector<bool> &visited, vector<bool> &path)
{
    path[source] = true;
    visited[source] = true;
    // visited[source] = 2;

    for (auto it : adj[source])
    {
        if (!visited[it] && dfs(it, adj, visited, path))
            return true;

        if (path[it])
            return true;
        // if (visited[it] == 2) return true;
    }

    path[source] = false;
    // visited[source] = 1;

    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<bool> path(V, false);
            if (dfs(i, adj, visited, path))
                return true;
        }
    }

    return false;
}