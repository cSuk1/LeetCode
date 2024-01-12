/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = (int)nums.size();
        if (n == 0)
        {
            return 0;
        }
        vector<int> dp(n, 1);
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end
