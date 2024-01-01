/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */
#include "a_header.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeElements(ListNode *head,
                             int val)
    {
        ListNode *cur = head;
        ListNode *pre = head;
        while (cur != nullptr)
        {
            if (cur->val == val)
            {
                if (cur == head)
                {
                    head = head->next;
                    delete cur;
                    cur = head;
                }
                else
                {
                    pre->next = cur->next;
                    delete cur;
                    cur = pre->next;
                }
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
// @lc code=end
