/*
 * @lc app=leetcode.cn id=LCR 127 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 127] 跳跃训练
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
    int trainWays(int num)
    {
        if (num < 2)
        {
            return 1;
        }
        vector<int> dp(2);
        dp[0] = 1;
        dp[1] = 2;
        for (size_t i = 2; i < num; i++)
        {
            int tmp = dp[1];
            dp[1] = (dp[0] + dp[1]) % 1000000007;
            dp[0] = tmp;
        }
        return dp[1];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

 */
