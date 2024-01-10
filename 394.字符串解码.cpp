/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    string decodeString(string s)
    {
        string ret;
        stack<string> stk;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (s[i] != ']' && (s[i] < '0' || s[i] > '9'))
            {
                stk.push(string(1, s[i]));
            }
            else if (s[i] == ']')
            {
                string tmp;
                while (stk.top() != "[")
                {
                    tmp = stk.top() + tmp;
                    stk.pop();
                }
                stk.pop();
                int num = stoi(stk.top());
                stk.pop();
                while (num--)
                {
                    stk.push(tmp);
                }
            }
            else
            {
                string strnum = string(1, s[i]);
                while (s[++i] >= '0' && s[i] <= '9')
                {
                    strnum = strnum + s[i];
                }
                stk.push(strnum);
                i--;
            }
        }
        while (!stk.empty())
        {
            ret = stk.top() + ret;
            stk.pop();
        }

        return ret;
    }
};
// @lc code=end
