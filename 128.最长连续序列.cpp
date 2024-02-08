/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int max[2] = {1, 0};
        int pre = nums[0];
        int set = nums[0];
        int cnt = 1;
        unordered_map<int, vector<int>> map;
        map[set].emplace_back(set);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - 1 == pre)
            {
                map[set].emplace_back(nums[i]);
                pre++;
                cnt++;
                if (cnt > max[0])
                {
                    max[0] = cnt;
                    max[1] = set;
                }
            }
            else if (nums[i] == pre)
            {
                continue;
            }
            else
            {
                cnt = 1;
                set = nums[i];
                pre = set;
                map[set].emplace_back(set);
            }
        }
        return max[0];
    }
};
// @lc code=end
