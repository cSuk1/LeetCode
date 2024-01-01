/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote,
                      string magazine)
    {
        unordered_map<char, int> magazine_map;
        bool ret = true;
        for (size_t i = 0; i < magazine.size(); i++)
        {
            if (magazine_map.find(magazine[i]) != magazine_map.end())
            {
                magazine_map[magazine[i]]++;
            }
            else
            {
                magazine_map[magazine[i]] = 1;
            }
        }

        for (auto &ch : ransomNote)
        {
            if (magazine_map.find(ch) == magazine_map.end() || magazine_map[ch] == 0)
            {
                ret = false;
            }
            if (magazine_map.find(ch) != magazine_map.end())
            {
                magazine_map[ch]--;
            }
        }
        return ret;
    }
};
// @lc code=end
