/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<vector<unordered_set<char>>>
            box(3, vector<unordered_set<char>>(3));
        for (size_t i = 0; i < 9; i++)
        {
            unordered_set<char> row;
            unordered_set<char> col;
            for (size_t j = 0; j < 9; j++)
            {
                if (row.find(board[i][j]) != row.end() ||
                    col.find(board[j][i]) != col.end() ||
                    box[i / 3][j / 3].find(board[i][j]) != box[i / 3][j / 3].end())
                {
                    return false;
                }
                if (board[i][j] != '.')
                {
                    row.insert(board[i][j]);
                    box[i / 3][j / 3].insert(board[i][j]);
                }
                if (board[j][i] != '.')
                {
                    col.insert(board[j][i]);
                }
            }
            row.clear();
            col.clear();
        }
        return true;
    }
};
// @lc code=end
