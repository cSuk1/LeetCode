/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode *addTwoNumbers(ListNode *l1,
                            ListNode *l2)
    {
        ListNode *cur = new ListNode();
        ListNode *head = cur;
        int carry = 0;
        while (l1 || l2)
        {
            cur->next = new ListNode();
            if (l1 && l2)
            {
                cur->next->val = (l1->val + l2->val + carry) % 10;
                carry = (l1->val + l2->val + carry) / 10;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1)
            {
                cur->next->val = (l1->val + carry) % 10;
                carry = (l1->val + carry) / 10;
                l1 = l1->next;
            }
            else
            {
                cur->next->val = (l2->val + carry) % 10;
                carry = (l2->val + carry) / 10;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (carry)
        {
            cur->next = new ListNode(carry);
            cur->next->next = nullptr;
        }
        return head->next;
    }
};
// @lc code=end
