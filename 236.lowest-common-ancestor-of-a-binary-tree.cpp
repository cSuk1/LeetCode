/*
 * @lc app=leetcode.cn id=236 lang=cpp
 * @lcpr version=30116
 *
 * [236] 二叉树的最近公共祖先
 */

// @lcpr-template-start
#include "a_header.h"
// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *dfs(TreeNode *root, int pv, int qv)
    {
        if (root == nullptr || root->val == pv || root->val == qv)
        {
            return root;
        }
        TreeNode *left = dfs(root->left, pv, qv);
        TreeNode *right = dfs(root->right, pv, qv);
        if (left != nullptr && right != nullptr)
        {
            return root;
        }
        else if (left != nullptr)
        {
            return left;
        }
        else
        {
            return right;
        }
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return dfs(root, p->val, q->val);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n2\n
// @lcpr case=end

 */
