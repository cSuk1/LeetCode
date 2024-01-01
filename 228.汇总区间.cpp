/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ret;
        string tmp;
        int pre;
        string start;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (tmp.length() == 0)
            {
                tmp += to_string(nums[i]);
                start = to_string(nums[i]);
                pre = nums[i];
                continue;
            }

            if (nums[i] == pre + 1)
            {
                if (tmp.length() == start.length())
                {
                    tmp += "->";
                }
                else
                {
                    int cnt = to_string(pre).size();
                    while (cnt--)
                    {
                        tmp.pop_back();
                    }
                }
                tmp += to_string(nums[i]);
                pre = nums[i];
            }
            else
            {
                ret.push_back(tmp);
                tmp.clear();
                i--;
            }
        }
        if (tmp.length() > 0)
        {
            ret.push_back(tmp);
        }
        return ret;
    }
};
// @lc code=end
