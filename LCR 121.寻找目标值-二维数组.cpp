/*
 * @lc app=leetcode.cn id=LCR 121 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 121] 寻找目标值 - 二维数组
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    bool findTargetIn2DPlants(vector<vector<int>> &plants, int target)
    {
        int h = plants.size();
        if (h == 0)
        {
            return false;
        }
        int w = plants[0].size();
        if (w == 0)
        {
            return false;
        }
        int m = 0, n = w - 1;
        while (m < h && n >= 0)
        {
            if (target > plants[m][n])
            {
                m++;
            }
            else if (target < plants[m][n])
            {
                n--;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[2,3,6,8],[4,5,8,9],[5,9,10,12]]\n8\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,5],[2,5,7]]\n4\n
// @lcpr case=end

 */
