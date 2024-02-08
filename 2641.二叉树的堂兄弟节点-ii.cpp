/*
 * @lc app=leetcode.cn id=2641 lang=cpp
 *
 * [2641] 二叉树的堂兄弟节点 II
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
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        unordered_map<TreeNode *, int> sameparent;
        queue<TreeNode *> q;
        q.push(root);
        sameparent[root] = 0;
        int sum = root->val;
        while (!q.empty())
        {
            int level_size = q.size();
            int tmp = sum;
            sum = 0;
            for (size_t i = 0; i < level_size; i++)
            {
                TreeNode *cur = q.front();
                cur->val = tmp - cur->val - sameparent[cur];

                if (cur->left)
                {
                    q.push(cur->left);
                    sameparent[cur->left] = cur->right ? cur->right->val : 0;
                    sum += cur->left->val;
                }
                if (cur->right)
                {
                    q.push(cur->right);
                    sameparent[cur->right] = cur->left ? cur->left->val : 0;
                    sum += cur->right->val;
                }
                q.pop();
            }
        }
        return root;
    }
};
// @lc code=end
