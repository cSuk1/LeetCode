/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */
#include "a_header.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    vector<int> ret;

public:
    void postorder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        ret.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        postorder(root);
        return ret;
    }
};
// @lc code=end
