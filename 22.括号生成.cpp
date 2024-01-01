/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    void backtrack(vector<string> &res,
                   string &tmp, int n,
                   int left, int right)
    {
        if (tmp.length() == n * 2)
        {
            res.push_back(tmp);
            return;
        }
        if (left > 0)
        {
            tmp.push_back('(');
            backtrack(res, tmp, n, left - 1, right);
            tmp.pop_back();
        }
        // 只有已经放入的左括号数量大于右括号时，才能是一个有效的括号串
        if (right > left)
        {
            tmp.push_back(')');
            backtrack(res, tmp, n, left, right - 1);
            tmp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string tmp;
        backtrack(res, tmp, n, n, n);
        return res;
    }
};
// @lc code=end
