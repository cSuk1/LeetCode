/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        unordered_map<char, int> m;
        for (int i = 0; i < 26; i++)
        {
            m['A' + i] = i + 1;
        }
        int ret = 0;
        for (int i = columnTitle.length() - 1; i >= 0; i--)
        {
            ret += m[columnTitle[i]] * pow(26, columnTitle.length() - 1 - i);
        }
        return ret;
    }
};
// @lc code=end
