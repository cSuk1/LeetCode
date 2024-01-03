/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        dp[0][0] = 1;
        vector<pair<int, int>> dirs = {
            {-1, 0},
            {0, -1},
        };
        for (int i = 0; i < obstacleGrid.size(); i++)
        {
            for (int j = 0; j < obstacleGrid[0].size(); j++)
            {
                for (auto dir : dirs)
                {
                    if (i + dir.first >= 0 &&
                        j + dir.second >= 0 &&
                        obstacleGrid[i + dir.first][j + dir.second] == 0)
                    {
                        dp[i][j] += dp[i + dir.first][j + dir.second];
                    }
                }
            }
        }
        return obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1 ? 0 : dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};
// @lc code=end
