/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int h = grid.size();
        int w = grid[0].size();
        queue<pair<int, int>> q;
        int minutes = -1;
        int fresh = 0;
        for (size_t i = 0; i < h; i++)
        {
            for (size_t j = 0; j < w; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        if (fresh == 0)
        {
            return 0;
        }
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty())
        {
            int edge_size = q.size();
            for (size_t i = 0; i < edge_size; i++)
            {
                pair<int, int> pos = q.front();
                q.pop();
                int m = pos.first;
                int n = pos.second;
                for (const auto &dir : directions)
                {
                    int nm = m + dir.first;
                    int nn = n + dir.second;

                    if (nm >= 0 && nm < h && nn >= 0 && nn < w && grid[nm][nn] == 1)
                    {
                        grid[nm][nn] = 2;
                        fresh--;
                        q.push({nm, nn});
                    }
                }
            }
            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
// @lc code=end
