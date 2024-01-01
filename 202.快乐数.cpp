/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> circle;
        while (circle.find(n) == circle.end())
        {
            circle.insert(n);
            string num = to_string(n);
            int len = num.length();
            n = 0;
            for (int i = 0; i < len; i++)
            {
                n += (num[i] - '0') * (num[i] - '0');
            }
            if (n == 1)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
