#include <bits/stdc++.h>
using namespace std;

bool bfs(int source, vector<int> adj[], vector<int> &color)
{
    queue<int> Q;

    Q.push(source);
    color[source] = 0;
    while (!Q.empty())
    {
        int node = Q.front();
        Q.pop();

        for (auto x : adj[node])
        {
            if (color[x] == -1)
            {
                color[x] = !color[node];
                Q.push(x);
            }
            else if (color[x] == color[node])
            {
                return false;
            }
        }
    }

    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1 && !bfs(i, adj, color))
            return false;
    }

    return true;
}