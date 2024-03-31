#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    vector<int> adj[N];

    for (int i = 0; i < M; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> distance(N);
    for (int i = 0; i < N; i++)
        distance[i] = 50000;

    queue<int> Q;
    Q.push(src);
    distance[src] = 0;
    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        for (auto it : adj[x])
        {
            if (distance[x] + 1 < distance[it])
            {
                distance[it] = distance[x] + 1;
                Q.push(it);
            }
        }
    }

    for (int i = 0; i < N; i++)
        if (distance[i] == 50000)
            distance[i] = -1;

    return distance;
}