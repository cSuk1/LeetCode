/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<int> vec;
        for (size_t i = 0; i < lists.size(); i++)
        {
            ListNode *p = lists[i];
            while (p != nullptr)
            {
                vec.push_back(p->val);
                p = p->next;
            }
        }
        ListNode *head = new ListNode();
        ListNode *cur = head;
        sort(vec.begin(), vec.end());
        for (size_t i = 0; i < vec.size(); i++)
        {
            ListNode *tmp = new ListNode(vec[i]);
            cur->next = tmp;
            cur = cur->next;
        }

        return head->next;
    }
};
// @lc code=end
