#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> distance(V, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[S] = 0;
    pq.push({0, S});

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            if (dis + it[1] < distance[it[0]])
            {
                distance[it[0]] = dis + it[1];
                pq.push({distance[it[0]], it[0]});
            }
        }
    }

    return distance;
}