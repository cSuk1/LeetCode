/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        vector<int> times(nums.size(), INT_MAX);
        times[0] = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = i + 1; j <= i + nums[i]; j++)
            {
                if (j == nums.size())
                {
                    break;
                }
                times[j] = min(times[j], times[i] + 1);
            }
        }
        return times[nums.size() - 1];
    }
};
// @lc code=end
