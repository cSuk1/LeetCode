/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 */
#include "a_header.h"
// @lc code=start
typedef pair<int, int> PII;
class Solution
{
public:
    bool canMeasureWater(int jug1Capacity,
                         int jug2Capacity,
                         int targetCapacity)
    {
        stack<PII> stk;
        auto hash_function = [](const PII &o)
        { return hash<int>()(o.first) ^ hash<int>()(o.second); };
        unordered_set<PII, decltype(hash_function)>
            visited(0, hash_function);
        stk.push({0, 0});
        while (!stk.empty())
        {
            if (visited.find(stk.top()) != visited.end())
            {
                stk.pop();
                continue;
            }
            visited.emplace(stk.top());
            PII node = stk.top();
            stk.pop();
            if (node.first == targetCapacity ||
                node.second == targetCapacity ||
                node.first + node.second == targetCapacity)
            {
                return true;
            }
            // fill 1
            stk.push({jug1Capacity, node.second});
            // fill 2
            stk.push({node.first, jug2Capacity});
            // empty 1
            stk.push({0, node.second});
            // empty 2
            stk.push({node.first, 0});
            // 1 to 2
            stk.push({0, (node.first + node.second) % jug2Capacity});
            // 2 to 1
            stk.push({(node.first + node.second) % jug1Capacity, 0});
        }
        return false;
    }
};
// @lc code=end
