#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>> &roads)
{
    vector<int> ways(n, 0);
    vector<int> dist(n, 1e9);
    vector<pair<int, int>> adj[n];

    for (int i = 0; i < roads.size(); i++)
    {
        adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
        adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
    }

    set<pair<int, int>> st;
    st.insert({0, 0});
    dist[0] = 0;
    ways[0] = 1;

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
                ways[x.first] = ways[node];
                st.insert({dist[x.first], x.first});
            }
            else if (distance + x.second == dist[x.first])
            {
                ways[x.first] += ways[node];
            }
        }
    }

    return ways[n - 1];
}