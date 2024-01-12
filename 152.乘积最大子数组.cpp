/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size(), vector<int>(3, 0));
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        dp[0][2] = nums[0];
        for (size_t i = 1; i < nums.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0] * nums[i], nums[i]);
            dp[i][0] = max(dp[i][0], dp[i - 1][1] * nums[i]);
            dp[i][1] = min(dp[i - 1][1] * nums[i], nums[i]);
            dp[i][1] = min(dp[i][1], dp[i - 1][0] * nums[i]);
            dp[i][2] = max(dp[i][0], dp[i - 1][2]);
        }
        return dp[nums.size() - 1][2];
    }
};
// @lc code=end
