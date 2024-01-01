/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */
#include "a_header.h"
// @lc code=start
// [1, 2, 1, 3, 5, 6, 4]
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int len = nums.size();
        int left = 0, right = len;
        int mid = (left + right) / 2;
        while (left < right && mid >= 0 && mid < len)
        {
            long left_val = mid - 1 >= 0 ? nums[mid - 1] : LONG_MIN;
            long right_val = mid + 1 < len ? nums[mid + 1] : LONG_MIN;
            if (nums[mid] <= right_val)
            {
                left = mid;
            }
            else if (nums[mid] <= left_val)
            {
                right = mid;
            }
            else
            {
                break;
            }
            mid = (left + right) / 2;
        }
        return mid;
    }
};
// @lc code=end
