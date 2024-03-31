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

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    int n = accounts.size();
    unordered_map<string, int> mapMailNode;

    DisjointSet ds(n);

    for (int i = 0; i < n; i++)
        for (int j = 1; j < accounts[i].size(); j++)
            if (mapMailNode.find(accounts[i][j]) == mapMailNode.end())
                mapMailNode[accounts[i][j]] = i;
            else
                ds.unionBySize(i, mapMailNode[accounts[i][j]]);

    vector<string> adj[n];
    for (auto it : mapMailNode)
        adj[ds.findUParent(it.second)].push_back(it.first);

    vector<vector<string>> ans;

    for (int i = 0; i < n; i++)
    {
        if (!adj[i].size())
            continue;
        sort(adj[i].begin(), adj[i].end());

        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for (auto it : adj[i])
            temp.push_back(it);
        ans.push_back(temp);
    }

    return ans;
}