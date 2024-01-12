/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int &num : nums)
        {
            sum += num;
        }
        if (sum % 2 != 0 || nums.empty())
        {
            return false;
        }
        int half = sum / 2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(half + 1, false));
        for (size_t i = 0; i < nums.size(); i++)
        {
            dp[i][0] = true;
        }
        if (nums[0] <= half)
        {
            if (nums[0] == half)
            {
                return true;
            }
            dp[0][nums[0]] = true;
        }
        for (size_t i = 1; i < nums.size(); i++)
        {
            for (size_t j = 0; j < half + 1; j++)
            {
                dp[i][j] = dp[i - 1][j] == true ? true : dp[i][j];
                if (dp[i - 1][j] && j + nums[i] <= half)
                {
                    if (j + nums[i] == half)
                    {
                        return true;
                    }
                    dp[i][j + nums[i]] = true;
                }
            }
        }
        return dp[nums.size() - 1][half];
    }
};
// @lc code=end
