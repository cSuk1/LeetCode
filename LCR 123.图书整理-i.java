/*
 * @lc app=leetcode.cn id=LCR 123 lang=java
 * @lcpr version=30116
 *
 * [LCR 123] 图书整理 I
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start

import java.util.ArrayList;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[] reverseBookList(ListNode head) {
        ListNode cur = head;
        ArrayList<Integer> list = new ArrayList<>();
        while (cur != null) {
            list.add(cur.val);
            cur = cur.next;
        }
        Collections.reverse(list);
        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}
// @lc code=end



/*
// @lcpr case=start
// [3,6,4,1]\n
// @lcpr case=end

 */

