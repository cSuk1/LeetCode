/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    vector<int> findSubstring(string s,
                              vector<string> &words)
    {
        vector<int> ret;
        int word_len = words[0].size();
        int substr_len = words.size() * word_len;
        unordered_map<string, int> words_map;
        for (string &word : words)
        {
            words_map[word]++;
        }
        for (size_t i = 0; i < word_len; i++)
        {
            for (size_t j = i; j < s.length() - substr_len + 1; j = j + word_len)
            {
                unordered_map<string, int> tmp_map;
                string tmp = s.substr(j, substr_len);
                for (size_t k = 0; k < words.size(); k++)
                {
                    tmp_map[tmp.substr(k * word_len, word_len)]++;
                }
                if (tmp_map == words_map)
                {
                    ret.push_back(j);
                }
            }
        }
        return ret;
    }
};
// @lc code=end
