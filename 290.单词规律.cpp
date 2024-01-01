/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern,
                     string s)
    {
        vector<string> words;
        string tmp;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                if (tmp.length() > 0)
                {
                    words.push_back(tmp);
                    tmp.clear();
                }
                continue;
            }
            tmp += s[i];
            if (s.length() == i + 1)
            {
                words.push_back(tmp);
            }
        }
        if (words.size() != pattern.length())
            return false;
        unordered_map<char, string> maps;
        unordered_set<string> hasMapped;
        int cnt = 0;
        for (auto &ch : pattern)
        {
            if (maps.find(ch) == maps.end() && hasMapped.find(words[cnt]) == hasMapped.end())
            {
                hasMapped.insert(words[cnt]);
                maps[ch] = words[cnt++];
            }
            else
            {
                if (maps[ch] != words[cnt++])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
