/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            // 如果整体有序
            if (nums[left] <= nums[right])
            {
                return nums[left];
            }
            // 如果mid的左边是有序的且右边无序，则最小值在右边
            else if (nums[left] <= nums[mid] && nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            // 如果mid的右边是有序的且左边无序，则最小值在左边
            else
            {
                right = mid;
            }
        }
        return -1;
    }
};
// @lc code=end
