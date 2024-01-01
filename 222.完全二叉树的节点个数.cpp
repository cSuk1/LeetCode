/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    void dfs(TreeNode *root, int &cnt)
    {
        if (root == nullptr)
        {
            return;
        }
        cnt++;
        dfs(root->left, cnt);
        dfs(root->right, cnt);
    }

    int countNodes(TreeNode *root)
    {
        int nums = 0;
        dfs(root, nums);
        return nums;
    }
};
// @lc code=end
