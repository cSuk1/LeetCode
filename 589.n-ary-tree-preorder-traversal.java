/*
 * @lc app=leetcode.cn id=589 lang=java
 * @lcpr version=30116
 *
 * [589] N 叉树的前序遍历
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
    private List<Integer> list;

    private void func(Node root){
        if(root == null){
            return;
        }
        list.add(root.val);
        for(Node node : root.children){
            func(node);
        }
    }

    public List<Integer> preorder(Node root) {
        list = new ArrayList<>();
        func(root);
        return list;
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,null,3,2,4,null,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]\n
// @lcpr case=end

 */

