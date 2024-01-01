/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include "a_header.h"
// @lc code=start
class Solution
{
private:
    vector<pair<int, int>> dirs =
        {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    bool dfs(vector<vector<char>> &board, string &word,
             vector<vector<bool>> &visted,
             int n, int i, int j, int h, int w)
    {
        if (word[n] != board[i][j] || visted[i][j])
        {
            return false;
        }
        else if (n == word.length() - 1)
        {
            return true;
        }
        int ret = false;
        visted[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            if (i + dirs[k].first >= 0 && i + dirs[k].first < h &&
                j + dirs[k].second >= 0 && j + dirs[k].second < w)
            {
                ret = ret || dfs(board, word, visted, n + 1, i + dirs[k].first, j + dirs[k].second, h, w);
            }
            if (ret)
            {
                break;
            }
        }
        visted[i][j] = false;
        return ret;
    }

    bool exist(vector<vector<char>> &board,
               string word)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visted(m, vector<bool>(n, false));
        bool ret = false;
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (word[0] == board[i][j])
                {
                    ret = ret || dfs(board, word, visted, 0, i, j, m, n);
                    if (ret)
                    {
                        return true;
                    }
                    else
                    {
                        fill(visted.begin(), visted.end(), vector<bool>(n, false));
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end
