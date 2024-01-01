/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int steps = cost.size();
        vector<int> dp(3, 0);
        for (size_t i = 2; i < steps; i++)
        {
            int tmp = dp[2];
            dp[2] = min(dp[1] + cost[i - 1], dp[0] + cost[i - 2]);
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        return dp[2];
    }
};
// @lc code=end
