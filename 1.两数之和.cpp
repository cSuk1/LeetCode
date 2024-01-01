/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums,
                       int target)
    {
        unordered_map<int, int> map;
        int cnt = 0;
        for (auto &num : nums)
        {
            map[num] = cnt;
            cnt++;
        }
        cnt = 0;
        for (auto &num : nums)
        {
            if (map.find(target - num) != map.end() && map[target - num] != cnt)
            {
                return {cnt, map[target - num]};
            }
            cnt++;
        }
        return {};
    }
};
// @lc code=end
