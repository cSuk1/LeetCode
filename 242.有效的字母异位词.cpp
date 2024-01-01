/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> map;
        for (size_t i = 0; i < s.length(); i++)
        {
            map[s[i]]++;
        }
        for (size_t i = 0; i < t.length(); i++)
        {
            map[t[i]]--;
        }
        for (auto &it : map)
        {
            if (it.second != 0)
                return false;
        }
        return true;
    };
};
// @lc code=end
