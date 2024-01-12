/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < amount + 1; i++)
        {
            for (int &coin : coins)
            {
                if (i - coin >= 0)
                {
                    int temp = dp[i - coin] == INT_MAX ? INT_MAX : dp[i - coin] + 1;
                    dp[i] = min(dp[i], temp);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
// @lc code=end
