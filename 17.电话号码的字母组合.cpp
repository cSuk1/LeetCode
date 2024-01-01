/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include "a_header.h"
// @lc code=start
class Solution
{
private:
    unordered_map<char, string> map = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

public:
    void findCombinations(string &digits,
                          vector<string> &res,
                          string &tmp,
                          int idx, int len)
    {
        if (tmp.length() == len)
        {
            res.push_back(tmp);
        }
        else
        {
            for (size_t i = 0; i < map[digits[idx]].length(); i++)
            {
                tmp.push_back(map[digits[idx]][i]);
                findCombinations(digits, res, tmp, idx + 1, len);
                tmp.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return {};
        }
        vector<string> res;
        string tmp;
        findCombinations(digits, res, tmp, 0, digits.length());
        return res;
    }
};
// @lc code=end
