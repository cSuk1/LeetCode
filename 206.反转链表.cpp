/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
private:
    ListNode *ret;

public:
    ListNode *re(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        if (head->next == nullptr)
        {
            ret = head;
        }
        ListNode *node = re(head->next);
        if (node != nullptr)
        {
            node->next = head;
            head->next = nullptr;
        }
        return head;
    }
    ListNode *reverseList(ListNode *head)
    {
        re(head);
        head = ret;
        return head;
    }
};
// @lc code=end
