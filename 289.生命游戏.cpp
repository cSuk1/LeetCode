/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int h = board.size();
        int w = board[0].size();
        vector<vector<int>> change(h, vector<int>(w, 0));
        vector<pair<int, int>> paths = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0},
            {1, 1},
            {1, -1},
            {-1, 1},
            {-1, -1}};
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                int live = 0;
                for (auto &path : paths)
                {
                    if (i + path.first >= 0 && i + path.first < h &&
                        j + path.second >= 0 && j + path.second < w)
                    {
                        int i_ = i + path.first;
                        int j_ = j + path.second;
                        if ((change[i_][j_] == 0 && board[i_][j_] == 1) ||
                            (change[i_][j_] == 1 && board[i_][j_] == 0))
                        {
                            live++;
                        }
                    }
                }
                if (board[i][j])
                {

                    if (live == 2 || live == 3)
                    {
                        continue;
                    }
                    board[i][j] = 0;
                    change[i][j] = 1;
                }
                else
                {
                    if (live == 3)
                    {
                        board[i][j] = 1;
                        change[i][j] = 1;
                    }
                }
            }
        }
    }
};
// @lc code=end
