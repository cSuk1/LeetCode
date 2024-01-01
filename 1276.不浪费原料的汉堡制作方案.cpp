/*
 * @lc app=leetcode.cn id=1276 lang=cpp
 *
 * [1276] 不浪费原料的汉堡制作方案
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    vector<int> numOfBurgers(int tomatoSlices,
                             int cheeseSlices)
    {
        int total = cheeseSlices;
        vector<int> ret;
        int total_jumbo, total_small;
        int i = 0;
        do
        {
            if (4 * i + 2 * (total - i) == tomatoSlices)
            {
                return {i, total - i};
            }
            i++;
        } while (i < total);
        return ret;
    }
};
// @lc code=end
