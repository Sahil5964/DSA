#include <bits/stdc++.h>
using namespace std;

void bfs(int V, vector<int> adj[], vector<int> &inDegree, vector<int> &ans)
{
    queue<int> Q;

    for (int i = 0; i < V; i++)
        if (!inDegree[i])
            Q.push(i);

    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        ans.push_back(x);
        for (auto it : adj[x])
        {
            inDegree[it]--;
            if (!inDegree[it])
                Q.push(it);
        }
    }
}

// Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
    stack<int> st;
    vector<int> ans;
    vector<int> inDegree(V, 0);

    for (int i = 0; i < V; i++)
        for (auto it : adj[i])
            inDegree[it]++;

    bfs(V, adj, inDegree, ans);

    return ans;
}