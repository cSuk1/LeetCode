/*
 * @lc app=leetcode.cn id=50 lang=java
 * @lcpr version=30116
 *
 * [50] Pow(x, n)
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
    public double myPow(double x, int n) {
        long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }

    public double quickMul(double x, long N) {
        if (N == 0) {
            return 1.0;
        }
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }
}
// @lc code=end

/*
 * // @lcpr case=start
 * // 2.00000\n10\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * // 2.10000\n3\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * // 2.00000\n-2\n
 * // @lcpr case=end
 * 
 */
