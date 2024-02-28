/*
 * @lc app=leetcode.cn id=106 lang=java
 * @lcpr version=30116
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private static int findIndex(int[] array, int target) {
        for (int i = 0; i < array.length; i++) {
            if (array[i] == target) {
                return i;
            }
        }
        return -1;
    }

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if(inorder.length == 0){
            return null;
        }
        if(inorder.length == 1){
            return new TreeNode(inorder[0]);
        }
        int inorderLen = inorder.length;
        int postorderLen = postorder.length;
        TreeNode node = new TreeNode(postorder[postorderLen-1]);
        int index = findIndex(inorder, postorder[postorderLen-1]);
        node.left = buildTree(Arrays.copyOfRange(inorder, 0, index),
                    Arrays.copyOfRange(postorder, 0, index));
        node.right = buildTree(Arrays.copyOfRange(inorder, index+1, inorderLen),
                    Arrays.copyOfRange(postorder, index, postorderLen-1));
        return node;
    }
}
// @lc code=end



/*
// @lcpr case=start
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

