/*
 * @lc app=leetcode.cn id=1962 lang=cpp
 *
 * [1962] 移除石子使总数最小
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        int heaps = piles.size();
        int sum = 0;
        if (piles.size() == 0)
        {
            return 0;
        }
        // 建堆
        make_heap(piles.begin(), piles.end());
        while (k--)
        {
            pop_heap(piles.begin(), piles.end());
            piles[heaps - 1] -= floor(piles[heaps - 1] / 2);
            push_heap(piles.begin(), piles.end());
        }
        for (int i = 0; i < heaps; i++)
        {
            sum += piles[i];
        }
        return sum;
    }
};
// @lc code=end
