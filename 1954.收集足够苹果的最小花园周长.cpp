/*
 * @lc app=leetcode.cn id=1954 lang=cpp
 *
 * [1954] 收集足够苹果的最小花园周长
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    long long minimumPerimeter(long long neededApples)
    {
        long long ret;
        int sum = 0;
        long long num = 0;
        for (ret = 0; sum < neededApples; ret++)
        {
            sum += 12 * ret * ret;
        }
        return 8 * (ret - 1);
    }
};
// @lc code=end
