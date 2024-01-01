/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas,
                           vector<int> &cost)
    {
        int n = gas.size();

        int totalSum = 0; // 总剩余汽油量
        int currSum = 0;  // 当前剩余汽油量
        int start = 0;    // 起始点

        for (int i = 0; i < n; i++)
        {
            int diff = gas[i] - cost[i];
            totalSum += diff;
            currSum += diff;

            if (currSum < 0)
            {
                // 当前剩余汽油量不够到达下一个加油站，重置起始点
                start = i + 1;
                currSum = 0;
            }
        }

        if (totalSum < 0 || start >= n)
        {
            // 总剩余汽油量小于0，无法绕行整个循环
            // 或者起始点超过了加油站数量，表示无解
            return -1;
        }

        return start;
    }
};
// @lc code=end
