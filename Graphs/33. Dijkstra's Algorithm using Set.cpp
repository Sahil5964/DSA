#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> distance(V, 1e9);
    set<pair<int, int>> st;

    distance[S] = 0;
    st.insert({0, S});
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
            }
        }
    }

    return distance;
}