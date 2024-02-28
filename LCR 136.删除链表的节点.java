/*
 * @lc app=leetcode.cn id=LCR 136 lang=java
 * @lcpr version=30116
 *
 * [LCR 136] 删除链表的节点
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        ListNode dummy = new ListNode();
        dummy.next = head;
        ListNode pre = dummy;
        ListNode cur = head;
        while (cur.val != val) {
            pre = pre.next;
            cur = cur.next;
        }
        pre.next = cur.next;
        return dummy.next;
    }
}
// @lc code=end

/*
 * // @lcpr case=start
 * // [4,5,1,9]\n5\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * // [4,5,1,9]\n1\n
 * // @lcpr case=end
 * 
 */
