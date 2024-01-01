/*
 * @lc app=leetcode.cn id=2415 lang=cpp
 *
 * [2415] 反转二叉树的奇数层
 */
// Definition for a binary tree node.
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
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            int size = q.size();
            bool flag = level % 2 == 1;
            vector<int> nums(size);
            int cnt = size;
            while (cnt--)
            {
                TreeNode *node = q.front();
                q.pop();
                if (flag)
                {
                    q.push(node);
                    nums[size - cnt - 1] = node->val;
                }
                else
                {
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }
            }
            if (flag)
            {
                cnt = size;
                while (cnt--)
                {
                    TreeNode *node = q.front();
                    node->val = nums[cnt];
                    q.pop();
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }
            }
            level++;
        }
        return root;
    }
};
// @lc code=end
