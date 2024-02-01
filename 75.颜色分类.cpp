/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n0 = 0;
        int n1 = 0;
        int n2 = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            switch (nums[i])
            {
            case 0:
                n0++;
                break;
            case 1:
                n1++;
                break;
            case 2:
                n2++;
                break;
            default:
                break;
            }
        }
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (i < n0)
            {
                nums[i] = 0;
            }
            else if (i < n0 + n1)
            {
                nums[i] = 1;
            }
            else
            {
                nums[i] = 2;
            }
        }
    }
};
// @lc code=end
