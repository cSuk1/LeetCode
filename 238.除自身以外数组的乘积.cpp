/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> pre;
        int len = nums.size();
        vector<int> answer(len, 0);
        int tmp = 1;
        pre.push_back(1);
        for (int i = 0; i < len; i++)
        {
            tmp = nums[i] * tmp;
            pre.push_back(tmp);
        }
        tmp = 1;
        for (int i = len - 1; i >= 0; i--)
        {
            answer[i] = pre[i] * tmp;
            tmp = nums[i] * tmp;
        }
        return answer;
    }
};
// @lc code=end
