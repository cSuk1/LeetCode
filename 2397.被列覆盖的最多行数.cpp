/*
 * @lc app=leetcode.cn id=2397 lang=cpp
 *
 * [2397] 被列覆盖的最多行数
 */
#include "a_header.h"
// @lc code=start
class Solution
{
private:
    int maxCovered;

public:
    int numOfCovered(vector<vector<int>> &matrix,
                     unordered_set<int> &selected)
    {
        int ret = matrix.size();
        for (size_t i = 0; i < matrix.size(); i++)
        {
            int flag = 0;
            for (size_t j = 0; j < matrix[0].size(); j++)
            {
                if (selected.find(j) == selected.end())
                {
                    flag |= matrix[i][j];
                    if (flag)
                    {
                        ret--;
                        break;
                    }
                }
            }
        }
        return ret;
    }

    void backtrack(vector<vector<int>> &matrix,
                   unordered_set<int> &selected,
                   int col,
                   int numSelect)
    {
        if (selected.size() == numSelect)
        {
            maxCovered = max(maxCovered, numOfCovered(matrix, selected));
            return;
        }
        for (int i = col; i < matrix[0].size(); i++)
        {
            selected.insert(i);
            backtrack(matrix, selected, i + 1, numSelect);
            selected.erase(i);
        }
    }

    int maximumRows(vector<vector<int>> &matrix,
                    int numSelect)
    {
        maxCovered = -1;
        unordered_set<int> selected;
        backtrack(matrix, selected, 0, numSelect);
        return maxCovered;
    }
};
// @lc code=end
