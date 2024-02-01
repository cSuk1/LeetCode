/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int len1 = word1.length();
        int len2 = word2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (size_t i = 0; i < len2 + 1; i++)
        {
            dp[0][i] = i;
        }

        for (size_t i = 0; i < len1 + 1; i++)
        {
            dp[i][0] = i;
        }

        for (size_t i = 1; i < len1 + 1; i++)
        {
            for (size_t j = 1; j < len2 + 1; j++)
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }
        return dp[len1][len2];
    }
};
// @lc code=end
