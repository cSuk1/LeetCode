/*
 * @lc app=leetcode.cn id=2859 lang=cpp
 *
 * [2859] 计算 K 置位下标对应元素的和
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int sumIndicesWithKSetBits(vector<int> &nums,
                               int k)
    {
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int bit = 0;
            bitset<32> bs(i);
            for (int j = 0; j < 32; ++j)
            {
                bit += bs[j] == 1 ? 1 : 0;
            }
            ret += bit == k ? nums[i] : 0;
        }
        return ret;
    }
};
// @lc code=end
