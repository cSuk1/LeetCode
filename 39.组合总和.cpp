/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    void findCombination(vector<int> &candidates,
                         int target,
                         int idx,
                         int len,
                         vector<int> &tmp,
                         vector<vector<int>> &result)
    {
        int sum = 0;
        for (auto &num : tmp)
        {
            sum += num;
        }
        if (sum == target)
        {
            result.push_back(tmp);
            return;
        }
        else if (sum > target)
        {
            return;
        }
        for (size_t i = idx; i < len; i++)
        {
            tmp.push_back(candidates[i]);
            findCombination(candidates, target, i, len, tmp, result);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates,
                                       int target)
    {
        vector<vector<int>> result;
        vector<int> tmp;
        findCombination(candidates, target, 0, candidates.size(), tmp, result);
        return result;
    }
};
// @lc code=end
