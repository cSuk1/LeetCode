/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix,
                      int target)
    {
        int row = matrix.size(), col = matrix[0].size();
        int st = 0, ed = row * col - 1;
        int mid, x, y;
        while (st <= ed)
        {
            mid = st + (ed - st) / 2;
            x = mid / col;
            y = mid - col * x;
            if (matrix[x][y] == target)
            {
                return true;
            }
            else if (matrix[x][y] > target)
            {
                ed = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end
