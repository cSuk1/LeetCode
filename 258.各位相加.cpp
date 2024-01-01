/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int addDigits(int num)
    {
        string tmp;
        while (num / 10 > 0)
        {
            tmp = to_string(num);
            num = 0;
            for (size_t i = 0; i < tmp.length(); i++)
            {
                num += tmp[i] - '0';
            }
        }
        return num;
    }
};
// @lc code=end
