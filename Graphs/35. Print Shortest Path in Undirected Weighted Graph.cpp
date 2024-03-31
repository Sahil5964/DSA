#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<int>> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    set<pair<int, int>> st;
    vector<int> parent(n + 1, -1);
    vector<int> distance(n + 1, 1e9);

    distance[1] = 0;
    st.insert({0, 1});

    while (!st.empty())
    {
        auto itr = *(st.begin());
        int dis = itr.first;
        int node = itr.second;
        st.erase(itr);

        for (auto it : adj[node])
        {
            if (dis + it[1] < distance[it[0]])
            {
                if (distance[it[0]] != 1e9)
                    st.erase({distance[it[0]], it[0]});
                distance[it[0]] = dis + it[1];
                st.insert({distance[it[0]], it[0]});
                parent[it[0]] = node;
            }
        }
    }

    int node = n;
    vector<int> ans;

    while (parent[node] != -1)
    {
        ans.push_back(node);
        node = parent[node];
    }
    ans.push_back(node);
    reverse(ans.begin(), ans.end());

    return (parent[n] == -1 ? vector<int>{-1} : ans);
}