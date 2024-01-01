/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    void backtrack(vector<int> &nums, vector<vector<int>> &res,
                   vector<int> &tmp, int n)
    {
        // 最后一个元素
        if (tmp.size() == n)
        {
            res.push_back(tmp);
            return;
        }
        else
        {
            for (size_t i = 0; i < n; i++)
            {
                // 如果这个元素没有被放入组合
                if (find(tmp.begin(), tmp.end(), nums[i]) == tmp.end())
                {
                    // 放入组合
                    tmp.push_back(nums[i]);
                    // 递归
                    backtrack(nums, res, tmp, n);
                    // 回溯
                    tmp.pop_back();
                }
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        int len = nums.size();
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(nums, res, tmp, len);
        return res;
    }
};
// @lc code=end
