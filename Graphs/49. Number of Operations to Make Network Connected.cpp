#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank;
    vector<int> size;

public:
    vector<int> parent;

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

int Solve(int n, vector<vector<int>> &edge)
{

    int extraEdges = 0;
    DisjointSet ds(n);

    for (auto e : edge)
        if (ds.findUParent(e[0]) == ds.findUParent(e[1]))
            extraEdges++;
        else
            ds.unionBySize(e[0], e[1]);

    int component = 0;
    for (int i = 0; i < n; i++)
        if (ds.parent[i] == i)
            component++;

    int requiredEdges = component - 1;
    return (extraEdges >= requiredEdges ? requiredEdges : -1);
}