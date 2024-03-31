#include <bits/stdc++.h>
using namespace std;

void bfs(int source, int V, vector<int> adj[], vector<int> &ans, vector<bool> &visited)
{
    queue<int> Q;
    Q.push(source);
    visited[source] = true;

    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        ans.push_back(x);

        for (auto i : adj[x])
        {
            if (!visited[i])
            {
                visited[i] = true;
                Q.push(i);
            }
        }
    }
}

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<bool> visited(V, false);

    bfs(0, V, adj, ans, visited);

    // for (int i = 0; i < V; i++)
    //     if (!visited[i]) {
    //         visited[i] = true;
    //         bfs(i, V, adj, ans, visited);
    //     }

    return ans;
}