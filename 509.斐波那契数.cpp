/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
        {
            return 0;
        }

        vector<int> dp(3, 0);
        dp[1] = 1;
        dp[2] = 1;
        for (size_t i = 2; i < n + 1; i++)
        {
            dp[2] = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }
};
// @lc code=end
