/*
 * @lc app=leetcode.cn id=LCR 135 lang=java
 * @lcpr version=30116
 *
 * [LCR 135] 报数
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
    public int[] countNumbers(int cnt) {
        int max = 1;
        while (cnt-- > 0) {
            max *= 10;
        }
        max -= 1;
        int[] res = new int[max];
        for (int i = 1; i <= max; i++) {
            res[i - 1] = i;
        }
        return res;
    }
}
// @lc code=end

/*
 * // @lcpr case=start
 * // 2\n
 * // @lcpr case=end
 * 
 */
