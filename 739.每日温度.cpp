/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> stk;
        vector<int> ret(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++)
        {
            if (stk.empty())
            {
                stk.push(i);
            }
            else
            {
                if (temperatures[i] <= temperatures[stk.top()])
                {
                    stk.push(i);
                }
                else
                {
                    while (!stk.empty() && temperatures[stk.top()] < temperatures[i])
                    {
                        ret[stk.top()] = i - stk.top();
                        stk.pop();
                    }
                    stk.push(i);
                }
            }
        }
        return ret;
    }
};
// @lc code=end
