/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        vector<pair<int, int>> dirs =
            {{-1, 0}, {0, -1}};
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (size_t k = 0; k < 2; k++)
                {

                    if (i + dirs[k].first >= 0 && j + dirs[k].second >= 0)
                    {
                        dp[i][j] += dp[i + dirs[k].first][j + dirs[k].second];
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
