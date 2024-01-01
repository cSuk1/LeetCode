/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int tribonacci(int n)
    {
        vector<int> dp(4);
        dp = {0, 1, 1, 2};
        if (n <= 3)
        {
            return dp[n];
        }

        for (size_t i = 3; i < n + 1; i++)
        {
            dp[3] = dp[0] + dp[1] + dp[2];
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = dp[3];
        }
        return dp[3];
    }
};
// @lc code=end
