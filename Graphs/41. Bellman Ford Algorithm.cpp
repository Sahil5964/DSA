#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> distance(V, 1e8);
    distance[S] = 0;

    for (int i = 0; i < V; i++)
        for (auto it : edges)
            if (distance[it[0]] + it[2] < distance[it[1]])
            {
                distance[it[1]] = distance[it[0]] + it[2];
                if (i == (V - 1))
                    return {-1};
            }

    return distance;
}