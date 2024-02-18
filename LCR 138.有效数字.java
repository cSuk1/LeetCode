/*
 * @lc app=leetcode.cn id=LCR 138 lang=java
 * @lcpr version=30116
 *
 * [LCR 138] 有效数字
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
    public boolean validNumber(String s) {
        String pattern = "\\s*[+-]?(\\d+\\.?|\\.\\d+|\\d+\\.\\d+)([Ee][+-]?\\d+)?\\s*";
        return s.matches(pattern);
    }
}
// @lc code=end

/*
 * // @lcpr case=start
 * // "0"\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * // "e"\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * // "."\n
 * // @lcpr case=end
 * 
 */
