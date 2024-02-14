/*
 * @lc app=leetcode.cn id=987 lang=java
 * @lcpr version=30116
 *
 * [987] 二叉树的垂序遍历
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private Map<Integer, List<TreeNode>> map = new HashMap<>();
    private Map<TreeNode, List<Integer>> nodeIndex = new HashMap<>();

    private int minCol;
    public void preOrderTravel(TreeNode root, int row, int col){
        if(root == null) {
            return;
        }
        if(col < minCol){
            minCol = col;
        }
        List<TreeNode> list = map.get(col);
        if(list == null){
            list = new ArrayList<>();
            list.add(root);
            map.put(col, list);
        }else{
            list.add(root);
        }
        nodeIndex.put(root, Arrays.asList(row, col));
        preOrderTravel(root.left, row+1, col-1);
        preOrderTravel(root.right, row+1, col+1);
    }

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        preOrderTravel(root, 0, 0);
        List<List<Integer>> result = new ArrayList<>(map.size());
        for (int i = 0; i < map.size(); i++) {
            result.add(new ArrayList<>());
        }
        map.forEach((k,v)->{
            // 按照col row val的优先级排序
            Collections.sort(v, (o1, o2) -> {
                List<Integer> pair1 = nodeIndex.get(o1);
                List<Integer> pair2 = nodeIndex.get(o2);
                int ret =  pair1.get(1) - pair2.get(1) == 0 ? pair1.get(0) - pair2.get(0) : pair1.get(1) - pair2.get(1);
                if(ret == 0){
                    return o1.val - o2.val;
                }
                return ret;
            });
            List<Integer> tmp = new ArrayList<>();
            for (TreeNode node: v) {
                tmp.add(node.val);
            }
            result.set(k - minCol, tmp);
        });
        return result;
    }
}
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,6,5,7]\n
// @lcpr case=end

 */

