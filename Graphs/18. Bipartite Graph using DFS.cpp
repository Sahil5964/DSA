#include <bits/stdc++.h>
using namespace std;

bool dfs(int source, vector<int> adj[], vector<int> &color, int c)
{
    color[source] = c;

    for (auto it : adj[source])
        if (color[it] == c || (color[it] == -1 && !dfs(it, adj, color, !c)))
            return false;

    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++)
        if (color[i] == -1 && !dfs(i, adj, color, 0))
            return false;

    return true;
}