/*
 * @lc app=leetcode.cn id=LCR 144 lang=java
 * @lcpr version=30116
 *
 * [LCR 144] 翻转二叉树
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
    public TreeNode mirrorTree(TreeNode root) {
        if (root == null) {
            return root;
        }
        TreeNode right = mirrorTree(root.left);
        TreeNode left = mirrorTree(root.right);
        root.right = right;
        root.left = left;
        return root;
    }
}
// @lc code=end

/*
 * // @lcpr case=start
 * // [5,7,9,8,3,2,4]\n
 * // @lcpr case=end
 * 
 */
