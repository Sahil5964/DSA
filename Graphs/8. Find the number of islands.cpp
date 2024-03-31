#include <bits/stdc++.h>
using namespace std;

void bfs(int sr, int sc, vector<vector<char>> &grid, vector<vector<bool>> &visited)
{
    queue<pair<int, int>> Q;
    Q.push({sr, sc});
    visited[sr][sc] = true;

    int n = grid.size();
    int m = grid[0].size();

    int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    while (!Q.empty())
    {
        pair<int, int> p = Q.front();
        Q.pop();

        for (int i = 0; i < 8; i++)
        {
            int newr = p.first + dr[i];
            int newc = p.second + dc[i];

            if (newr >= 0 && newc >= 0 && newr < n && newc < m && grid[newr][newc] == '1' && !visited[newr][newc])
            {
                Q.push({newr, newc});
                visited[newr][newc] = true;
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int island = 0;

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1' && !visited[i][j])
            {
                island++;
                bfs(i, j, grid, visited);
            }
        }
    }

    return island;
}