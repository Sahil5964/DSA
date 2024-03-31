#include <bits/stdc++.h>
using namespace std;

int dijkstra(int source, int n, vector<pair<int, int>> adj[], int distanceThreshold)
{
    vector<int> dist(n, 1e9);
    set<pair<int, int>> st;
    int count = 0;

    dist[source] = 0;
    st.insert({0, source});
    while (!st.empty())
    {
        auto it = *(st.begin());
        int node = it.second;
        int distance = it.first;
        st.erase(it);

        for (auto x : adj[node])
        {
            if (distance + x.second < dist[x.first])
            {
                dist[x.first] = distance + x.second;
                st.insert({dist[x.first], x.first});
            }
        }
    }

    for (auto e : dist)
        if (e <= distanceThreshold)
            count++;

    return count;
}

int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<pair<int, int>> adj[n];

    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    int city = -1;
    int Neighbour = 1e9;

    for (int i = 0; i < n; i++)
    {
        int curNeighbour = dijkstra(i, n, adj, distanceThreshold);
        if (curNeighbour <= Neighbour)
        {
            Neighbour = curNeighbour;
            city = i;
        }
    }

    return city;
}