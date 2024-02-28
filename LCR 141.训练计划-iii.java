/*
 * @lc app=leetcode.cn id=LCR 141 lang=java
 * @lcpr version=30116
 *
 * [LCR 141] 训练计划 III
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    private ListNode res;

    private ListNode reverseList(ListNode head) {
        if (head == null) {
            return null;
        }
        if (head.next == null) {
            res = head;
            return head;
        }
        ListNode node = reverseList(head.next);
        node.next = head;
        head.next = null;
        return head;
    }

    public ListNode trainningPlan(ListNode head) {
        reverseList(head);
        return res;
    }
}
// @lc code=end

/*
 * // @lcpr case=start
 * // [1,2,3,4,5]\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * // [1,2]\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * // []\n
 * // @lcpr case=end
 * 
 */
