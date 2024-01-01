/*
 * @lc app=leetcode.cn id=1154 lang=cpp
 *
 * [1154] 一年中的第几天
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int dayOfYear(string date)
    {
        vector<int> monthDays =
            {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        int ret = day;
        for (size_t i = 0; i < month - 1; i++)
        {
            ret += monthDays[i];
        }
        return ret + (((year % 4 == 0 && year % 100 != 0) ||
                       (year % 100 == 0 && year % 400 == 0)) &&
                              month > 2
                          ? 1
                          : 0);
    }
};
// @lc code=end
