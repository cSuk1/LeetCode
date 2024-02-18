/*
 * @lc app=leetcode.cn id=LCR 139 lang=java
 * @lcpr version=30116
 *
 * [LCR 139] 训练计划 I
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
    public int[] trainingPlan(int[] actions) {
        int fast = 0, slow = 0;
        while (fast < actions.length) {
            if (actions[fast] % 2 == 1) {
                int tmp = actions[fast];
                actions[fast] = actions[slow];
                actions[slow] = tmp;
                slow++;
            }
            fast++;
        }
        return actions;
    }
}
// @lc code=end

/*
 * // @lcpr case=start
 * // [1,2,3,4,5]\n
 * // @lcpr case=end
 * 
 */
