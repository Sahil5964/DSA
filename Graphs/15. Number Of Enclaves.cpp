#include <bits/stdc++.h>
using namespace std;

int dfs(int sr, int sc, vector<vector<int>> &grid, vector<vector<bool>> &visited)
{
    int n = grid.size();
    int m = grid[0].size();

    visited[sr][sc] = true;

    int ans = 1;
    int dr[4] = {+1, -1, 0, 0};
    int dc[4] = {0, 0, +1, -1};

    for (int i = 0; i < 4; i++)
    {
        int nr = sr + dr[i];
        int nc = sc + dc[i];

        if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] && !visited[nr][nc])
            ans += dfs(nr, nc, grid, visited);
    }

    return ans;
}

int numberOfEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int ans = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 || j == 0 || i == (n - 1) || j == (m - 1)) && !visited[i][j] && grid[i][j])
            {
                dfs(i, j, grid, visited);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j])
            {
                ans += dfs(i, j, grid, visited);
            }
        }
    }

    return ans;
}