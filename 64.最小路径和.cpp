/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
#include "a_header.h"
// @lc code=start
#define MIN(x, y) x > y ? y : x
class Solution
{
private:
    vector<pair<int, int>> dir = {
        {-1, 0},
        {0, -1},
    };

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    if (i + dir[k].first >= 0 &&
                        j + dir[k].second >= 0)
                    {
                        dp[i][j] = MIN(dp[i][j],
                                       dp[i + dir[k].first][j + dir[k].second] + grid[i][j]);
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
