/*
 * @lc app=leetcode.cn id=LCR 146 lang=java
 * @lcpr version=30116
 *
 * [LCR 146] 螺旋遍历二维数组
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
    public int[] spiralArray(int[][] array) {
        if (array == null || array.length == 0 || array[0].length == 0) {
            return new int[0];
        }
        int h = array.length;
        int w = array[0].length;
        int[] res = new int[h * w];
        int top = 0, bottom = h - 1, left = 0, right = w - 1;
        int cnt = 0;
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                res[cnt++] = array[top][i];
            }
            top++;
            if (top > bottom) {
                break;
            }
            for (int i = top; i <= bottom; i++) {
                res[cnt++] = array[i][right];
            }
            right--;
            if (left > right) {
                break;
            }
            for (int i = right; i >= left; i--) {
                res[cnt++] = array[bottom][i];
            }
            bottom--;
            for (int i = bottom; i >= top; i--) {
                res[cnt++] = array[i][left];
            }
            left++;
        }
        return res;
    }
}
// @lc code=end

/*
 * // @lcpr case=start
 * // [[1,2,3],[8,9,4],[7,6,5]]\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * // [[1,2,3,4],[12,13,14,5],[11,16,15,6],[10,9,8,7]]\n
 * // @lcpr case=end
 * 
 */
