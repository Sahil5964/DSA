#include <bits/stdc++.h>
using namespace std;

bool bfs(int source, vector<int> adj[], vector<bool> &visited)
{
    queue<pair<int, int>> Q;
    Q.push({source, -1});
    visited[source] = true;

    while (!Q.empty())
    {
        int node = Q.front().first;
        int parent = Q.front().second;
        Q.pop();

        for (auto x : adj[node])
        {
            if (visited[x] && x != parent)
                return true;

            if (!visited[x])
            {
                visited[x] = true;
                Q.push({x, node});
            }
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && bfs(i, adj, visited))
            return true;
    }

    return false;
}