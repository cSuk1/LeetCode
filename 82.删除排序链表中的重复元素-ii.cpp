/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *cur = new ListNode(0);
        cur->next = head;
        ListNode *ret = cur;
        ListNode *tmp = head;
        while (cur->next->next)
        {
            if (cur->next->val == cur->next->next->val)
            {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x)
                {
                    ListNode *del = cur->next;
                    delete del;
                    cur->next = cur->next->next;
                }
            }else{
                cur = cur->next;
            }
        }
        return ret;
    }
};
// @lc code=end
