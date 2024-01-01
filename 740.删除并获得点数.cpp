/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> dp(maxNum + 1, 0);

        for (int num : nums)
        {
            dp[num] += num;
        }

        int prev = 0;
        int curr = 0;

        for (int i = 1; i <= maxNum; i++)
        {
            int temp = curr;
            curr = max(prev + dp[i], curr);
            prev = temp;
        }

        return curr;
    }
};
// @lc code=end
