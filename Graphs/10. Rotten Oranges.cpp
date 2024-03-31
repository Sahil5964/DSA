#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int ans = 0;
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<bool>> visited(n, vector<bool> (m, false));
    vector<vector<int>> data = grid;
    
    queue<pair<pair<int, int>, int>> Q;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                Q.push({{i, j}, 0});
            }
        }
    }
    
    int dr[4] = {+1, -1,  0,  0};
    int dc[4] = { 0,  0, +1, -1};
    
    while (!Q.empty()) {
        pair<int, int> p = Q.front().first;
        ans = max(ans, Q.front().second);
        Q.pop();
        
        for (int i = 0; i < 4; i++) {
            int newr = p.first + dr[i];
            int newc = p.second + dc[i];
            
            if (newr >= 0 && newc >= 0 && newr < n && newc < m && data[newr][newc] == 1) {
                data[newr][newc] = 2;
                Q.push({{newr, newc}, ans + 1});
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (data[i][j] == 1) {
                return -1;
            }
        }
    }
    
    return ans;
}