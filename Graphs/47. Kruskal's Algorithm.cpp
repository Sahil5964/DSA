#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank;
    vector<int> size;
    vector<int> parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1);
        parent.resize(n + 1);

        for (int i = 0; i < n; i++)
        {
            size[i] = 1;
            parent[i] = i;
        }
    }

    int findUParent(int node)
    {
        if (parent[node] == node)
            return node;
        return node = findUParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int UP_u = findUParent(u);
        int UP_v = findUParent(v);

        if (UP_u == UP_v)
            return;

        if (rank[UP_u] == rank[UP_v])
        {
            parent[UP_v] = UP_u;
            rank[UP_u] += 1;
        }
        else if (rank[UP_u] < rank[UP_v])
            parent[UP_u] = UP_v;
        else
            parent[UP_v] = UP_u;
    }

    void unionBySize(int u, int v)
    {
        int UP_u = findUParent(u);
        int UP_v = findUParent(v);

        if (UP_u == UP_v)
            return;

        if (size[UP_u] <= size[UP_v])
        {
            parent[UP_u] = UP_v;
            size[UP_v] += size[UP_u];
        }
        else
        {
            parent[UP_v] = UP_u;
            size[UP_u] += size[UP_v];
        }
    }
};

int kruskal(int V, vector<vector<int>> adj[])
{
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < V; i++)
        for (auto it : adj[i])
            edges.push_back({it[1], {it[0], i}});

    sort(edges.begin(), edges.end());

    int sum = 0;
    DisjointSet d(V);
    for (auto edge : edges)
    {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (d.findUParent(u) != d.findUParent(v))
        {
            sum += wt;
            d.unionBySize(u, v);
        }
    }

    return sum;
}