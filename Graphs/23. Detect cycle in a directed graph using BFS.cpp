#include <bits/stdc++.h>
using namespace std;

bool bfs(int V, vector<int> adj[])
{
    int count = 0;
    queue<int> Q;
    vector<int> inDegree(V, 0);

    for (int i = 0; i < V; i++)
        for (auto it : adj[i])
            inDegree[it]++;

    for (int i = 0; i < V; i++)
        if (!inDegree[i])
            Q.push(i);

    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        count++;
        for (auto it : adj[x])
        {
            inDegree[it]--;
            if (!inDegree[it])
                Q.push(it);
        }
    }

    return (count == V ? false : true);
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V, 0);

    // for (int i = 0; i < V; i++) {
    //     if (!visited[i]) {
    //         vector<bool> path(V, false);
    //         if (dfs(i, adj, visited, path))
    //             return true;
    //     }
    // }

    return bfs(V, adj);
    // return false;
}