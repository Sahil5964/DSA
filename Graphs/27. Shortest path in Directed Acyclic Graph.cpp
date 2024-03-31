#include <bits/stdc++.h>
using namespace std;

void dfs(int source, vector<pair<int, int>> adj[], vector<bool> &visited, stack<int> &st)
{
    visited[source] = true;

    for (auto it : adj[source])
        if (!visited[it.first])
            dfs(it.first, adj, visited, st);

    st.push(source);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[N];

    for (int i = 0; i < M; i++)
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});

    // Topological Sort
    vector<bool> visited(N, false);
    stack<int> st;

    for (int i = 0; i < N; i++)
        if (!visited[i])
            dfs(i, adj, visited, st);

    // Distance Matrix
    vector<int> distance(N);
    for (int i = 0; i < N; i++)
        distance[i] = 50000;

    distance[0] = 0;
    while (!st.empty())
    {
        int x = st.top();
        st.pop();

        for (auto it : adj[x])
            distance[it.first] = min(distance[x] + it.second, distance[it.first]);
    }

    for (int i = 0; i < N; i++)
        if (distance[i] == 50000)
            distance[i] = -1;

    return distance;
}