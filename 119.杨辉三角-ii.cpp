/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> res(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; i++)
        {
            for (int j = i - 1; j >= 1; j--)
            {
                res[j] = res[j - 1] + res[j];
            }
        }
        return res;
    }
};
// @lc code=end
