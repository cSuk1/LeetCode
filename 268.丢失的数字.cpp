/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i)
            {
                return i;
            }
        }
        return nums.size();
    }
};
// @lc code=end
