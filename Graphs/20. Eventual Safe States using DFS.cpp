#include <bits/stdc++.h>
using namespace std;

bool dfs(int source, vector<int> adj[], vector<bool> &visited, vector<bool> &path, vector<bool> &check)
{
    path[source] = true;
    check[source] = false;
    visited[source] = true;
    // visited[source] = 2;

    for (auto it : adj[source])
    {
        if (!visited[it] && dfs(it, adj, visited, path, check))
            return true;

        if (path[it])
            return true;
        // if (visited[it] == 2) return true;
    }

    check[source] = true;
    path[source] = false;
    // visited[source] = 1;

    return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    vector<bool> path(V, false);
    vector<bool> check(V, false);
    vector<bool> visited(V, false);
    vector<int> safeNodes;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(i, adj, visited, path, check);
    }

    for (int i = 0; i < V; i++)
        if (check[i])
            safeNodes.push_back(i);

    return safeNodes;
}