/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */
#include "a_header.h"
// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 0, right = n - 1;
        int ret;
        int mid;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (isBadVersion(mid))
            {
                right = mid - 1;
                ret = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ret;
    }
};
// @lc code=end
