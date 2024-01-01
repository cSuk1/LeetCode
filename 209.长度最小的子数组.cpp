/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target,
                       vector<int> &nums)
    {
        int left = 0, right = 0;
        int sum = 0;
        pair<int, int> ret = {0, nums.size() + 1};
        while (right < nums.size())
        {

            sum += nums[right];
            right++;

            while (sum >= target)
            {
                if (right - left < ret.second - ret.first)
                {
                    ret = {left, right};
                }
                sum -= nums[left];
                left++;
            }
        }
        return ret.second - ret.first <= nums.size()
                   ? ret.second - ret.first
                   : 0;
    }
};
// @lc code=end
