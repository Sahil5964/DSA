#include <bits/stdc++.h>
using namespace std;

string dfs(int sr, int sc, vector<vector<int>> &grid, vector<vector<bool>> &visited)
{
    int n = grid.size();
    int m = grid[0].size();

    visited[sr][sc] = true;

    int dr[4] = {-1, 0, +1, 0};
    int dc[4] = {0, +1, 0, -1};
    string dir = "URDL";

    string direction = "";

    for (int i = 0; i < 4; i++)
    {
        int nr = sr + dr[i];
        int nc = sc + dc[i];

        if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] && !visited[nr][nc])
        {
            direction += dir[i] + dfs(nr, nc, grid, visited) + dir[(i + 2) % 4];
        }
    }

    return direction;
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    set<string> st;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] && !visited[i][j])
            {
                st.insert(dfs(i, j, grid, visited));
            }
        }
    }

    return st.size();
}