/*
 * @lc app=leetcode.cn id=LCR 128 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 128] 库存管理 I
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
    int stockManagement(vector<int> &stock)
    {
        int low = 0;
        int high = stock.size() - 1;
        while (low < high)
        {
            int pivot = low + (high - low) / 2;
            // 右边有序
            if (stock[pivot] < stock[high])
            {
                high = pivot;
            }
            // 右边无序
            else if (stock[pivot] > stock[high])
            {
                low = pivot + 1;
            }
            else
            {
                high -= 1;
            }
        }
        return stock[low];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,5,8,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [5,7,9,1,2]\n
// @lcpr case=end

 */
