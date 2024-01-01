/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        unordered_map<int, char> m;
        string ret;
        m[0] = 'Z';
        for (int i = 1; i <= 26; i++)
        {
            m[i] = 'A' + i - 1;
        }
        int tmp = columnNumber;
        while (tmp > 0)
        {
            ret = m[tmp % 26] + ret;
            tmp = (tmp - 1) / 26;
        }
        return ret;
    }
};
// @lc code=end
