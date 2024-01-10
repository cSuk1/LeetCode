/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int row = triangle.size();
        int ret = triangle[0][0];
        for (int i = 1; i < row; i++)
        {
            ret = INT_MAX;
            for (int j = 0; j < triangle[i].size(); j++)
            {
                int upper = INT_MAX;
                if (j != triangle[i].size() - 1)
                {
                    upper = triangle[i - 1][j];
                }
                if (j - 1 >= 0)
                {
                    upper = min(upper, triangle[i - 1][j - 1]);
                }
                triangle[i][j] += upper;
                if (i == row - 1)
                {
                    ret = min(ret, triangle[i][j]);
                }
            }
        }
        return ret;
    }
};
// @lc code=end
