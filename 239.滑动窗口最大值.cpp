/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ret;
        priority_queue<pair<int, int>> pq;
        for (size_t i = 0; i < k; i++)
        {
            pq.emplace(nums[i], i);
        }
        for (size_t i = k; i < nums.size(); i++)
        {
            ret.push_back(pq.top().first);
            while (!pq.empty() && pq.top().second <= i - k)
            {
                pq.pop();
            }
            pq.emplace(nums[i], i);
        }
        if (!pq.empty())
        {
            ret.push_back(pq.top().first);
        }

        return ret;
    }
};
// @lc code=end
