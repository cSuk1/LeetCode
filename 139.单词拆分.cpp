/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    bool wordBreak(string s,
                   vector<string> &wordDict)
    {
        unordered_set<string> dict;
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (string &word : wordDict)
        {
            dict.insert(word);
        }
        for (int i = 0; i < s.length(); i++)
        {
            string tmp;
            for (int j = i; j >= 0; j--)
            {
                tmp = s.substr(j, i - j + 1);
                if (dict.find(tmp) != dict.end() &&
                    dp[j])
                {
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};
// @lc code=end
