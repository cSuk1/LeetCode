/*
 * @lc app=leetcode.cn id=429 lang=java
 * @lcpr version=30116
 *
 * [429] N 叉树的层序遍历
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        Queue<Node> queue = new LinkedList<>();
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        queue.add(root);
        int levelSize = 0;
        while (!queue.isEmpty()) {
            levelSize = queue.size();
            Node node = null;
            List<Integer> level = new ArrayList<>();
            for (int i = 0; i < levelSize; i++) {
                node = queue.poll();
                level.add(node.val);
                for (int j = 0; j < node.children.size(); j++) {
                    queue.add(node.children.get(j));
                }
            }
            res.add(level);
        }
        return res;
    }
}
// @lc code=end

/*
 * // @lcpr case=start
 * // [1,null,3,2,4,null,5,6]\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * //
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,
 * null,null,14]\n
 * // @lcpr case=end
 * 
 */
