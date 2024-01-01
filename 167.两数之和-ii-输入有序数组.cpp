/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums,
                       int target)
    {
        vector<int> idx(2, 0);
        int left = 0, right = nums.size() - 1;
        int tmp = 0;
        while (left < right)
        {
            tmp = nums[left] + nums[right];
            if (tmp == target)
            {
                idx[0] = left + 1;
                idx[1] = right + 1;
                break;
            }
            else if (tmp < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return idx;
    }
};
// @lc code=end
