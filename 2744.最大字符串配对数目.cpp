/*
 * @lc app=leetcode.cn id=2744 lang=cpp
 *
 * [2744] 最大字符串配对数目
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int maximumNumberOfStringPairs(vector<string> &words)
    {
        unordered_set<string> set;
        int ret = 0;
        for (string &word : words)
        {
            if (set.find(word) != set.end())
            {
                ret++;
            }
            else
            {
                reverse(word.begin(), word.end());
                set.insert(word);
            }
        }
        return ret;
    }
};
// @lc code=end
