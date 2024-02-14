/*
 * @lc app=leetcode.cn id=LCR 124 lang=java
 * @lcpr version=30116
 *
 * [LCR 124] 推理二叉树
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
    public TreeNode deduceTree(int[] preorder, int[] inorder) {
        if(preorder.length == 0){
            return null;
        }
        TreeNode tree = new TreeNode(preorder[0]);
        int index = 0;
        for (int i = 0; i < inorder.length; i++) {
            if (inorder[i] == preorder[0]) {
                index = i;
                break;
            }
        }
        tree.left = deduceTree(Arrays.copyOfRange(preorder, 1, 1 + index),
                Arrays.copyOfRange(inorder, 0, index));
        tree.right = deduceTree(Arrays.copyOfRange(preorder, 1 + index, preorder.length),
                Arrays.copyOfRange(inorder, index + 1, inorder.length));
        return tree;
    }
}
// @lc code=end

/*
 * // @lcpr case=start
 * // [3,9,20,15,7]\n[9,3,15,20,7]\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * // [-1]\n[-1]\n
 * // @lcpr case=end
 * 
 */
