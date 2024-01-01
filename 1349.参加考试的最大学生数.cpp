/*
 * @lc app=leetcode.cn id=1349 lang=cpp
 *
 * [1349] 参加考试的最大学生数
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int maxStudents(vector<vector<char>> &seats)
    {
        int m = seats.size();
        int n = seats[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(1 << n));
    }
};
// @lc code=end
