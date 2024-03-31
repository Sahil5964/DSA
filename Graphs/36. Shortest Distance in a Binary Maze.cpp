#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
{
    int n = grid.size();
    int m = grid[0].size();

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    queue<pair<pair<int, int>, int>> Q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    Q.push({source, 0});
    visited[source.first][source.second] = true;
    while (!Q.empty())
    {
        pair<int, int> p = Q.front().first;
        int distance = Q.front().second;
        Q.pop();

        if (p == destination)
            return distance;

        for (int i = 0; i < 4; i++)
        {
            int nr = p.first + dr[i];
            int nc = p.second + dc[i];

            if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] && !visited[nr][nc])
            {
                visited[nr][nc] = true;
                Q.push({{nr, nc}, distance + 1});
            }
        }
    }

    return -1;
}