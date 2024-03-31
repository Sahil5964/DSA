#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int n = image.size();
    int m = image[0].size();

    vector<vector<int>> ans = image;
    int oldColor = image[sr][sc];

    if (newColor == oldColor)
        return ans;

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    queue<pair<int, int>> Q;
    Q.push({sr, sc});
    ans[sr][sc] = newColor;

    while (!Q.empty())
    {
        pair<int, int> p = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newr = p.first + dr[i];
            int newc = p.second + dc[i];

            if (newr >= 0 && newc >= 0 && newr < n && newc < m && ans[newr][newc] == oldColor)
            {
                ans[newr][newc] = newColor;
                Q.push({newr, newc});
            }
        }
    }

    return ans;
}