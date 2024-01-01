/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    void findSubsets(vector<int> &nums,
                     vector<vector<int>> &res,
                     vector<int> &tmp,
                     int idx,
                     int len)
    {
        res.push_back(tmp);
        for (size_t i = idx; i < len; i++)
        {
            tmp.push_back(nums[i]);
            findSubsets(nums, res, tmp, i + 1, len);
            tmp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        int len = nums.size();
        vector<vector<int>> res;
        vector<int> tmp;
        findSubsets(nums, res, tmp, 0, len);
        return res;
    }
};
// @lc code=end
