/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> ret;
        int left = 0, right = 0;
        int start = 0;
        unordered_map<char, int> map;
        for (size_t i = 0; i < s.length(); i++)
        {
            map[s[i]] = i;
        }
        while (left <= right)
        {
            while (map[s[left]] < right)
            {
                left++;
            }
            right = map[s[left]];
            if (right == s.length() - 1)
            {
                ret.push_back(right - start + 1);
                break;
            }
            bool flag = true;
            for (size_t j = start; j < right; j++)
            {
                if (map[s[j]] > right)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ret.push_back(right - start + 1);
                left = right + 1;
                right = left;
                start = left;
            }
            else
            {
                left++;
            }
        }
        return ret;
    }
};

// @lc code=end
