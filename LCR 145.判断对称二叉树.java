/*
 * @lc app=leetcode.cn id=LCR 145 lang=java
 * @lcpr version=30116
 *
 * [LCR 145] 判断对称二叉树
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start

import java.util.List;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    public boolean checkSymmetricTree(TreeNode root) {
        return check(root, root);
    }

    public boolean check(TreeNode p, TreeNode q) {
        if (p == null && q == null) {
            return true;
        }
        if (p == null || q == null) {
            return false;
        }
        return p.val == q.val && check(p.left, q.right) && check(p.right, q.left);
    }
}
// @lc code=end

/*
 * // @lcpr case=start
 * // [6,7,7,8,9,9,8]\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * // [1,2,2,null,3,null,3]\n
 * // @lcpr case=end
 * 
 */
