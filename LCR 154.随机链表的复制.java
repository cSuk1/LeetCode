/*
 * @lc app=leetcode.cn id=LCR 154 lang=java
 * @lcpr version=30116
 *
 * [LCR 154] 复杂链表的复制
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        Node dummy = new Node(0);
        Map<Node, List<Node>> rands = new HashMap<>();
        Map<Node, Node> nodes = new HashMap<>();
        Node pre = dummy;
        while (head != null) {
            Node tmp = new Node(head.val);
            pre.next = tmp;
            pre = tmp;
            // 添加新旧节点映射
            nodes.put(head, tmp);
            // 如果该节点有随机指针
            if (head.random != null) {
                if (rands.containsKey(head.random)) {
                    List<Node> randomList = rands.get(head.random);
                    randomList.add(tmp);

                } else {
                    List<Node> randomList = new ArrayList<>();
                    randomList.add(tmp);
                    rands.put(head.random, randomList);
                }

            }
            head = head.next;
        }
        Node cur = dummy.next;

        for (Map.Entry<Node, List<Node>> entry : rands.entrySet()) {
            List<Node> randomList = entry.getValue();
            Node randomNode = entry.getKey();
            for (Node node : randomList) {
                node.random = nodes.get(randomNode);
            }
        }

        return dummy.next;
    }
}
// @lc code=end

/*
 * // @lcpr case=start
 * // [[7,null],[13,0],[11,4],[10,2],[1,0]]\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * // [[1,1],[2,1]]\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * // [[3,null],[3,0],[3,null]]\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * // []\n
 * // @lcpr case=end
 * 
 */
