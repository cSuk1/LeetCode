/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums,
                                 int k)
    {
        unordered_set<int> set;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (set.find(nums[i])!= set.end())
                return true;
            set.insert(nums[i]);
            if (i >= k)
                set.erase(nums[i - k]);
        }
        return false;

    }
};
// @lc code=end
