/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
public:
    void dfs(TreeNode *root, string &tmp, vector<string> &ret)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            ret.push_back(tmp + to_string(root->val));
            return;
        }
        string new_tmp = tmp + to_string(root->val) + "->";
        dfs(root->left, new_tmp, ret);
        dfs(root->right, new_tmp, ret);
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ret;
        string tmp;
        dfs(root, tmp, ret);
        return ret;
    }
};
// @lc code=end
