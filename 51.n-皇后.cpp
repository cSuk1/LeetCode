/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    bool isValid(vector<string> &cur,
                 int i, int j, int n)
    {
        // 判断当前位置是否合法 列
        for (size_t m = 0; m < i; m++)
        {
            if (cur[m][j] == 'Q')
            {
                return false;
            }
        }
        // 判断当前位置是否合法 斜线
        int row = i, col = j;
        while (--row >= 0 && --col >= 0)
        {
            if (cur[row][col] == 'Q')
            {
                return false;
            }
        }
        row = i, col = j;
        while (--row >= 0 && ++col < n)
        {
            if (cur[row][col] == 'Q')
            {
                return false;
            }
        }
        return true;
    }

    void backtrack(vector<vector<string>> &ret,
                   vector<string> &cur,
                   int n,
                   int row)
    {
        if (row == n)
        {
            ret.push_back(cur);
            return;
        }
        else
        {
            for (size_t i = 0; i < n; i++)
            {
                if (isValid(cur, row, i, n))
                {
                    cur[row][i] = 'Q';
                    backtrack(ret, cur, n, row + 1);
                }
                cur[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ret;
        vector<string> cur(n, string(n, '.'));
        backtrack(ret, cur, n, 0);
        return ret;
    }
};
// @lc code=end
