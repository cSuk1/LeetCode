/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = s.length();
        pair<int, int> ret = {0, 0};
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for (size_t i = 0; i < len; i++)
        {
            dp[i][i] = true;
        }
        // 子串长度
        for (size_t i = 2; i <= len; i++)
        {
            // 从0开始遍历长度为i的子串
            for (size_t j = 0; j <= len - i; j++)
            {
                if (s[j] == s[j + i - 1])
                {
                    if (i == 2)
                    {
                        dp[j][j + i - 1] = true;
                    }
                    else
                    {
                        dp[j][j + i - 1] = dp[j + 1][j + i - 2];
                    }
                    if (dp[j][j + i - 1])
                    {
                        ret = {j, j + i - 1};
                    }
                }
            }
        }

        return s.substr(ret.first, ret.second - ret.first + 1);
    }
};
// @lc code=end
