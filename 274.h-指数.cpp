/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int hindex = 0, l = citations.size() - 1;
        sort(citations.begin(), citations.end());
        while (l >= 0 && citations[l] > hindex)
        {
            hindex++;
            l--;
        }
        return hindex;
    }
};
// @lc code=end
