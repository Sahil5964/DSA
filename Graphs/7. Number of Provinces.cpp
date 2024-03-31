#include <bits/stdc++.h>
using namespace std;

void bfs(int source, vector<vector<int>> adj, vector<bool> &visited)
{
    queue<int> Q;
    Q.push(source);
    visited[source] = true;

    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        for (int i = 0; i < adj[x].size(); i++)
        {
            if (adj[x][i] && !visited[i])
            {
                visited[i] = true;
                Q.push(i);
            }
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V)
{
    int provinces = 0;

    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            provinces++;
            bfs(i, adj, visited);
        }
    }

    return provinces;
}