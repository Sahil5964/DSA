#include <bits/stdc++.h>
using namespace std;

int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
    vector<pair<int, int>> adj[n];
    
    for (int i = 0; i < flights.size(); i++)
        adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
    
    vector<int> distance(n, 1e9);
    queue<pair<int, pair<int, int>>> Q;
    
    distance[src] = 0;
    Q.push({0, {src, 0}});
    while (!Q.empty()) {
        int stop = Q.front().first;
        int node = Q.front().second.first;
        int dist = Q.front().second.second;
        Q.pop();
        
        if (stop > K) continue;
        
        for (auto it : adj[node]) {
            int neighbour = it.first;
            int weight = it.second;
            
            if (dist + weight < distance[neighbour] && stop <= K) {
                distance[neighbour] = dist + weight;
                Q.push({stop + 1, {neighbour, distance[neighbour]}});
            }
        }
    }
    
    return (distance[dst] == 1e9 ? -1 : distance[dst]);
}