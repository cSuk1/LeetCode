/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        string tmp;
        string res;
        vector<string> words;
        for (size_t i = 0; i < s.length(); i++)
        {
            tmp += s[i];
            if (s[i] == ' ' || i == s.length() - 1)
            {
                if (s[i] == ' ')
                    tmp.pop_back();
                if (tmp.length() > 0)
                {
                    words.push_back(tmp);
                    tmp.clear();
                }
            }
        }
        for_each(words.rbegin(), words.rend(), [&res](string &word)
                 { res+=word;res+=' '; });
        res.pop_back();
        return res;
    }
};
// @lc code=end
