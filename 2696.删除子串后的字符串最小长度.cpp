/*
 * @lc app=leetcode.cn id=2696 lang=cpp
 *
 * [2696] 删除子串后的字符串最小长度
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int minLength(string s)
    {
        stack<char> stk;
        unordered_map<char, char> map;
        map['A'] = 'B';
        map['C'] = 'D';
        int ret = 0;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (stk.empty())
            {
                stk.push(s[i]);
            }
            else
            {
                if (map[stk.top()] == s[i])
                {
                    stk.pop();
                }
                else
                {
                    stk.push(s[i]);
                }
            }
        }
        while (!stk.empty())
        {
            stk.pop();
            ret++;
        }
        return ret;
    }
};
// @lc code=end
