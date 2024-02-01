/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 2; i++)
        {
            int target = -nums[i];
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] == target)
                {
                    ret.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] + nums[right] == target)
                    {
                        left++;
                    }
                    while (left < right && nums[left] + nums[right] == target)
                    {
                        right--;
                    }
                    while (i < nums.size() - 2 && -nums[i + 1] == target)
                    {
                        i++;
                    }
                }
                else if (nums[left] + nums[right] < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return ret;
    }
};
// @lc code=end
