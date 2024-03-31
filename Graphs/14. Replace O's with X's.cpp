#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    queue<pair<int, int>> Q;
    vector<vector<char>> ans(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            ans[i][j] = 'X';
            if ((i == 0 || j == 0 || i == (n - 1) || j == (m - 1)) && mat[i][j] == 'O')
            {
                Q.push({i, j});
                ans[i][j] = 'O';
                visited[i][j] = true;
            }
        }

    int dr[4] = {+1, -1, 0, 0};
    int dc[4] = {0, 0, +1, -1};

    while (!Q.empty())
    {
        pair<int, int> p = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newr = p.first + dr[i];
            int newc = p.second + dc[i];

            if (newr >= 0 && newc >= 0 && newr < n && newc < m && mat[newr][newc] == 'O' && !visited[newr][newc])
            {
                ans[newr][newc] = 'O';
                visited[newr][newc] = true;
                Q.push({newr, newc});
            }
        }
    }

    return ans;
}