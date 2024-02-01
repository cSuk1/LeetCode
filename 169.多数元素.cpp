/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int ret = 0;
        int max = 0;
        for (int num : nums)
        {
            if (num > max)
            {
                max = num;
            }
        }
        bitset<sizeof(max) * 8> binary(max);
        int cnt;
        cnt = binary.size();
        for (int i = 0; i < cnt; i++)
        {
            int zero = 0;
            int one = 0;
            for (int num : nums)
            {
                if (num & (1 << i))
                {
                    one++;
                }
                else
                {
                    zero++;
                }
            }
            if (one > zero)
            {
                ret |= (1 << i);
            }
        }
        return ret;
    }
};
// @lc code=end
