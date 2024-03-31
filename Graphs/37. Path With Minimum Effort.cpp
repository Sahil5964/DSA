#include <bits/stdc++.h>
using namespace std;

int MinimumEffort(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    set<pair<int, pair<int, int>>> st;
    vector<vector<int>> diff(n, vector<int>(m, 1e9));

    diff[0][0] = 0;
    st.insert({0, {0, 0}});
    while (!st.empty())
    {
        auto itr = *(st.begin());
        int effort = itr.first;
        pair<int, int> p = itr.second;
        st.erase(itr);

        if (diff[n - 1][m - 1] < effort)
            break;

        for (int i = 0; i < 4; i++)
        {
            int nr = p.first + dr[i];
            int nc = p.second + dc[i];

            if (nr >= 0 && nc >= 0 && nr < n && nc < m)
            {
                int newEffort = max(abs(heights[nr][nc] - heights[p.first][p.second]), effort);
                if (newEffort < diff[nr][nc])
                {
                    diff[nr][nc] = newEffort;
                    st.insert({newEffort, {nr, nc}});
                }
            }
        }
    }

    return diff[n - 1][m - 1];
}