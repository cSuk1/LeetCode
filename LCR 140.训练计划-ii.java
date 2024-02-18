/*
 * @lc app=leetcode.cn id=LCR 140 lang=java
 * @lcpr version=30116
 *
 * [LCR 140] 训练计划 II
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
    public ListNode trainingPlan(ListNode head, int cnt) {
        ListNode fast = head;
        ListNode slow = head;
        while (fast != null && cnt-- > 0) {
            fast = fast.next;
        }
        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }
        return slow;
    }
}
// @lc code=end

/*
 * // @lcpr case=start
 * // [2,4,7,8]\n1\n
 * // @lcpr case=end
 * 
 */
