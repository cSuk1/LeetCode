/*
 * @lc app=leetcode.cn id=LCR 143 lang=java
 * @lcpr version=30116
 *
 * [LCR 143] 子结构判断
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private boolean result;

    private boolean subStruct(TreeNode A, TreeNode B) {
        if (B == null) {
            return true;
        }
        if (A == null) {
            return false;
        }
        boolean left = false;
        boolean right = false;
        if (A.val == B.val) {
            left = subStruct(A.left, B.left);
            right = subStruct(A.right, B.right);
            return left && right;
        } else {
            return false;
        }
    }

    private void dfs(TreeNode A, TreeNode B) {
        if (A == null) {
            return;
        }
        if (A.val == B.val) {
            result = subStruct(A, B);
        }
        dfs(A.left, B);
        dfs(A.right, B);
    }

    public boolean isSubStructure(TreeNode A, TreeNode B) {
        if (B == null) {
            return false;
        }
        dfs(A, B);
        return result;
    }
}
// @lc code=end

/*
 * // @lcpr case=start
 * // [1,7,5]\n[6,1]\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * // [3,6,7,1,8]\n[6,1]\n
 * // @lcpr case=end
 * 
 */
