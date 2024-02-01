/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int trap(vector<int> &heights)
    {
        int len = heights.size();
        int left = 0, right = len - 1;
        // 当前遍历到的左右的最高高度
        int left_height = 0, right_height = 0;
        int height;
        int water = 0;
        while (left < right)
        {
            // 如果左边柱子高度较低
            if (heights[left] <= heights[right])
            {
                height = heights[left];
                // 更新左边最高高度，这一列无法接到雨水
                if (height > left_height)
                {
                    left_height = height;
                }
                else
                {
                    // 这一列可以接到雨水
                    water += left_height - height;
                }
                // 向右移动
                left++;
            }
            else
            {
                // 如果右边柱子高度较低
                height = heights[right];
                // 更新右边最高高度，这一列无法接到雨水
                if (height > right_height)
                {
                    right_height = height;
                }
                else
                {
                    // 这一列可以接到雨水
                    water += right_height - height;
                }
                // 向左移动
                right--;
            }
        }
        return water;
    }
};
// @lc code=end
