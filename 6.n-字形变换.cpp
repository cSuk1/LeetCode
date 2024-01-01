/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] N 字形变换
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    string convert(string s,
                   int numRows)
    {
        int cnt = s.length();
        int cols = (2 * numRows + 1) * cnt / ((2 * numRows - 2) == 0 ? 1 : (2 * numRows - 2));
        vector<vector<char>> g(numRows, vector<char>(cols, '#'));
        int col = 0;
        int tmp = 0;
        int tmp2 = numRows - 2 < 0 ? 0 : numRows - 2;
        int change = numRows - 1 == 0 ? 1 : numRows - 1;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (col % change == 0)
            {
                g[tmp++][col] = s[i];
                if (tmp == numRows)
                {
                    col++;
                    tmp = 0;
                    tmp2 = numRows - 2 < 0 ? 0 : numRows - 2;
                }
            }
            else
            {
                g[tmp2--][col] = s[i];
                col++;
            }
        }
        string ret;
        for (size_t i = 0; i < numRows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                if (g[i][j] != '#')
                {
                    ret += g[i][j];
                }
            }
        }
        return ret;
    }
};
// @lc code=end
