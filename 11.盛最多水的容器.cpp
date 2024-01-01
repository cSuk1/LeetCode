/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include "a_header.h"
// @lc code=start
#define MAX(x, y) x > y ? x : y
#define MIN(x, y) x > y ? y : x
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int max = -1;
        while (left < right)
        {
            int area = (right - left) * (MIN(height[left], height[right]));
            max = MAX(max, area);
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return max;
    }
};
// @lc code=end
