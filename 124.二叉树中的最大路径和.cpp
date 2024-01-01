/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
#define MAX(a, b) (a > b ? a : b)
class Solution
{
private:
    int max;

public:
    int travel(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = travel(root->left);
        int right = travel(root->right);
        // 找到以root为根节点的最大路径和
        int ans = MAX(root->val, root->val + left);
        ans = MAX(ans, root->val + right);
        ans = MAX(ans, root->val + left + right);
        // 更新最大路径和
        max = MAX(ans, max);
        // 返回以root为线段起点的一条最大路径和
        return MAX(root->val, root->val + MAX(left, right));
    }
    int maxPathSum(TreeNode *root)
    {
        max = INT_MIN;
        travel(root);
        return max;
    }
};
// @lc code=end
