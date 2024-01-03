/*
 * @lc app=leetcode.cn id=2487 lang=cpp
 *
 * [2487] 从链表中移除节点
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
    ListNode *removeNode(ListNode *head,
                         stack<ListNode *> &st)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        head->next = removeNode(head->next, st);
        if (st.empty())
        {
            st.push(head);
        }
        else
        {
            if (st.top()->val > head->val)
            {
                delete head;
                return st.top();
            }
            else
            {
                st.push(head);
            }
        }
        return head;
    }

    ListNode *removeNodes(ListNode *head)
    {
        stack<ListNode *> st;
        return removeNode(head, st);
    }
};
// @lc code=end
