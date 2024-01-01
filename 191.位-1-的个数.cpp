/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int sum = 0;
        for (size_t i = 0; i < 32; i++)
        {
            if ((n & (1 << i)) == 1 << i)
            {
                sum++;
            }
        }
        return sum;
    }
};
// @lc code=end
