#include <bits/stdc++.h>
using namespace std;

string findOrder(string dict[], int N, int K)
{
    vector<int> adj[K];

    for (int i = 1; i < N; i++)
    {
        int j = 0;

        while (dict[i - 1][j] == dict[i][j] && j < dict[i - 1].size() && j < dict[i].size())
            j++;

        if (j < dict[i - 1].size() && j < dict[i].size())
            adj[dict[i - 1][j] - 'a'].push_back(dict[i][j] - 'a');
    }

    // Topological Sorting

    queue<int> Q;
    string ans = "";
    vector<int> inDegree(K, 0);

    for (int i = 0; i < K; i++)
        for (auto it : adj[i])
            inDegree[it]++;

    for (int i = 0; i < K; i++)
        if (!inDegree[i])
            Q.push(i);

    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        ans.push_back((char)('a' + x));
        for (auto it : adj[x])
        {
            inDegree[it]--;
            if (!inDegree[it])
                Q.push(it);
        }
    }

    return ans;
}