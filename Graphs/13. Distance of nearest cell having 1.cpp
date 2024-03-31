#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int, int>, int>> Q;
    vector<vector<int>> dis(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j])
            {
                visited[i][j] = true;
                Q.push({{i, j}, 0});
            }
        }
    }

    int dr[4] = {-1, +1, 0, 0};
    int dc[4] = {0, 0, +1, -1};

    while (!Q.empty())
    {
        pair<int, int> p = Q.front().first;
        int distance = Q.front().second;
        dis[p.first][p.second] = distance;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newr = p.first + dr[i];
            int newc = p.second + dc[i];

            if (newr >= 0 && newc >= 0 && newr < n && newc < m && !grid[newr][newc] && !visited[newr][newc])
            {
                visited[newr][newc] = true;
                Q.push({{newr, newc}, distance + 1});
            }
        }
    }

    return dis;
}