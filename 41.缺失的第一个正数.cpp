/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        bool first = true;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0 && first)
            {
                first = false;
                if (nums[i] != 1)
                {
                    return 1;
                }
                continue;
            }
            if (!first && nums[i] - nums[i - 1] > 1)
            {
                return nums[i - 1] + 1;
            }
        }
        return nums[nums.size() - 1] + 1 > 0 ? nums[nums.size() - 1] + 1 : 1;
    }
};
// @lc code=end
