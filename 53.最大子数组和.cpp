/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include "a_header.h"
// @lc code=start
#define MAX(x, y) (x > y ? x : y)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max = nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for (size_t i = 1; i < nums.size(); i++)
        {
            dp[i] = MAX(nums[i], dp[i - 1] + nums[i]);
            max = MAX(max, dp[i]);
        }
        return max;
    }
};
// @lc code=end
