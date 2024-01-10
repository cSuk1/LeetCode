/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int len = nums.size();
        int far = 0;
        for (int i = 0; i < len; ++i)
        {
            if (i <= far)
            {
                far = max(far, i + nums[i]);
                if (far >= len - 1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
