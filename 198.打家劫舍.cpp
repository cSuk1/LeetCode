/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include "a_header.h"
// @lc code=start
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x > y ? y : x)
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(3, 0);
        dp[1] = nums[0];
        dp[2] = nums[0];
        for (size_t i = 1; i < nums.size(); i++)
        {
            dp[2] = MAX(dp[1], nums[i] + dp[0]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }
};
// @lc code=end
