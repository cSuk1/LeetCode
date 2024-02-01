/*
 * @lc app=leetcode.cn id=2788 lang=cpp
 *
 * [2788] 按分隔符拆分字符串
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    vector<string> splitWordsBySeparator(vector<string> &words, char separator)
    {
        vector<string> ret;
        for (string &str : words)
        {
            string tmp;
            for (size_t i = 0; i < str.length(); i++)
            {
                if (str[i] != separator)
                {
                    tmp += str[i];
                }
                else if (tmp.length() > 0)
                {
                    ret.push_back(tmp);
                    tmp.clear();
                }
            }
            if (tmp.length() > 0)
            {
                ret.push_back(tmp);
                tmp.clear();
            }
        }
        return ret;
    }
};
// @lc code=end
