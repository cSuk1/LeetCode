/*
 * @lc app=leetcode.cn id=10 lang=java
 * @lcpr version=30116
 *
 * [10] 正则表达式匹配
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
    public boolean isMatch(String s, String p) {
        int articleLen = s.length();
        int inputLen = p.length();
        boolean[][] dp = new boolean[articleLen + 1][inputLen + 1];
        dp[0][0] = true;
        for (int i = 0; i < articleLen + 1; i++) {
            for (int j = 1; j < inputLen + 1; j++) {
                // 为通配符
                if (p.charAt(j - 1) == '*') {
                    // 至少匹配到0个
                    dp[i][j] = dp[i][j - 2];
                    if (i > 0) {
                        if (p.charAt(j - 2) == s.charAt(i - 1) || p.charAt(j - 2) == '.') {
                            dp[i][j] = dp[i][j] || dp[i - 1][j];
                        }
                    }
                    // 不为通配符
                } else if (i > 0) {
                    // 如果元素能匹配
                    if (p.charAt(j - 1) == s.charAt(i - 1) || p.charAt(j - 1) == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[articleLen][inputLen];
    }
}
// @lc code=end

/*
 * // @lcpr case=start
 * // "aa"\n"a"\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * // "aa"\n"a*"\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * // "ab"\n".*"\n
 * // @lcpr case=end
 * 
 */
