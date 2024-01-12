/*
 * @lc app=leetcode.cn id=2085 lang=cpp
 *
 * [2085] 统计出现过一次的公共字符串
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int countWords(vector<string> &words1,
                   vector<string> &words2)
    {
        unordered_map<string, pair<int, int>> mp;
        for (string &word : words1)
        {
            if (mp.find(word) != mp.end())
            {
                mp[word].first++;
            }
            else
            {
                mp[word] = make_pair(1, 0);
            }
        }
        for (string &word : words2)
        {
            if (mp.find(word) != mp.end())
            {
                mp[word].second++;
            }
        }
        int res = 0;
        for (auto &item : mp)
        {
            if (item.second.first == 1 &&
                item.second.second == 1)
            {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
