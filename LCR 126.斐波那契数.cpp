/*
 * @lc app=leetcode.cn id=LCR 126 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 126] 斐波那契数
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
    int fib(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        vector<int> dp(2);
        dp[0] = 0;
        dp[1] = 1;
        int tmp = 0;
        for (size_t i = 2; i <= n; i++)
        {
            tmp = (dp[0] + dp[1]) % 1000000007;
            dp[0] = dp[1];
            dp[1] = tmp;
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
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */
