/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int lower(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int mid;
        int ret = -1;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                ret = mid;
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ret;
    }

    vector<int> searchRange(vector<int> &nums,
                            int target)
    {
        vector<int> ret(2, -1);
        ret[0] = lower(nums, target);
        if (ret[0] == -1)
        {
            return ret;
        }
        ret[1] = ret[0];
        int cnt = ret[0];
        while (++cnt < nums.size() && nums[cnt] == target)
        {
            ret[1] = cnt;
        }
        return ret;
    }
};
// @lc code=end
