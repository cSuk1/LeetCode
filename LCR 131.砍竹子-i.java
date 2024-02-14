/*
 * @lc app=leetcode.cn id=LCR 131 lang=java
 * @lcpr version=30116
 *
 * [LCR 131] 砍竹子 I
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start

class Solution {
    public int cuttingBamboo(int bamboo_len) {
        int[] dp = new int[bamboo_len + 1];
        int tmp = 0;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i < bamboo_len + 1; i++) {
            dp[i] = Math.max(dp[i - 1], i - 1);
            tmp = Math.max(dp[i - 2] * 2, 2 * i - 4);
            dp[i] = Math.max(dp[i], tmp);
            tmp = Math.max(dp[i - 3] * 3, 3 * i - 9);
            dp[i] = Math.max(dp[i], tmp);
        }
        return dp[bamboo_len];
    }
}
// @lc code=end

/*
 * // @lcpr case=start
 * // 12\n
 * // @lcpr case=end
 * 
 */
