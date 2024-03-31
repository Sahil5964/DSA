#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    int sum = 0;
    vector<bool> visited(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = true;
        sum += distance;

        for (auto x : adj[node])
        {
            if (!visited[x[0]])
                pq.push({x[1], x[0]});
        }
    }

    return sum;
}