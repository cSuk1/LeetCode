/*
 * @lc app=leetcode.cn id=2660 lang=cpp
 *
 * [2660] 保龄球游戏的获胜者
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int isWinner(vector<int> &player1,
                 vector<int> &player2)
    {
        int sum1 = player1[0], sum2 = player2[0];
        if (player1.size() > 1)
        {
            sum1 += sum1 == 10 ? 2 * player1[1] : player1[1];
            sum2 += sum2 == 10 ? 2 * player2[1] : player2[1];
        }
        for (size_t i = 2; i < player1.size(); i++)
        {
            sum1 += (player1[i - 1] == 10 || player1[i - 2] == 10) ? 2 * player1[i] : player1[i];
            sum2 += (player2[i - 1] == 10 || player2[i - 2] == 10) ? 2 * player2[i] : player2[i];
        }
        return sum1 == sum2 ? 0 : (sum1 > sum2 ? 1 : 2);
    }
};
// @lc code=end
