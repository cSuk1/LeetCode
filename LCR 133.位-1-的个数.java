/*
 * @lc app=leetcode.cn id=LCR 133 lang=java
 * @lcpr version=30116
 *
 * [LCR 133] 位 1 的个数
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            if ((n & 1) == 1) {
                result++;
            }
            n = n >> 1;
        }
        return result;
    }
}
// @lc code=end

/*
 * // @lcpr case=start
 * // 11 (控制台输入 00000000000000000000000000001011)\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * // 128 (控制台输入 00000000000000000000000010000000)\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * // -3）\n
 * // @lcpr case=end
 * 
 */
