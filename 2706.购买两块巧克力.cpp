/*
 * @lc app=leetcode.cn id=2706 lang=cpp
 *
 * [2706] 购买两块巧克力
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        sort(prices.begin(), prices.end(), [](int &a, int &b)
             { return a < b; });
        int ret = money - prices[0] - prices[1];
        return ret < 0 ? money : ret;
    }
};
// @lc code=end
