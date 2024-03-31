#include <bits/stdc++.h>
using namespace std;

void dfs(int source, vector<int> adj[], vector<bool> &visited, stack<int> &st)
{
    visited[source] = true;

    for (auto it : adj[source])
        if (!visited[it])
            dfs(it, adj, visited, st);

    st.push(source);
}

// Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
    stack<int> st;
    vector<int> ans;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs(i, adj, visited, st);

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}