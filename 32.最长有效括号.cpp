/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int cur = 0;
        int ret = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ')')
            {
                if (stk.top() != -1 && s[stk.top()] == '(')
                {
                    stk.pop();
                    cur = i - stk.top();
                    ret = max(ret, cur);
                }
                else
                {
                    stk.push(i);
                }
            }
            else
            {
                stk.push(i);
            }
        }
        return ret;
    }
};
// @lc code=end
