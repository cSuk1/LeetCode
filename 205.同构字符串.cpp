/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */
#include "a_header.h">
// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        bool ret = true;
        unordered_map<char, char> s_t_map;
        unordered_set<char> t_mapped;
        int len = s.length();
        for (size_t i = 0; i < len; i++)
        {
            if (s_t_map.find(s[i]) == s_t_map.end())
            {
                if (t_mapped.find(t[i]) != t_mapped.end())
                {
                    ret = false;
                    break;
                }
                s_t_map[s[i]] = t[i];
                t_mapped.insert(t[i]);
            }
            else
            {
                if (s_t_map[s[i]] != t[i])
                {
                    ret = false;
                    break;
                }
            }
        }
        return ret;
    }
};
// @lc code=end
