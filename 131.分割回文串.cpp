/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    bool isPalindrome(string str)
    {
        int n = str.length();
        for (int i = 0; i < n / 2; i++)
        {
            if (str[i] != str[n - i - 1])
            {
                return false;
            }
        }
        return true;
    }

    void backtrack(vector<vector<string>> &ret,
                   vector<string> &cur,
                   string &s,
                   int idx)
    {
        if (idx == s.length())
        {
            ret.push_back(cur);
        }
        for (int i = idx; i < s.length(); ++i)
        {
            if (isPalindrome(s.substr(idx, i - idx + 1)))
            {
                cur.push_back(s.substr(idx, i - idx + 1));
                backtrack(ret, cur, s, i + 1);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ret;
        vector<string> cur;
        backtrack(ret, cur, s, 0);
        return ret;
    }
};
// @lc code=end
