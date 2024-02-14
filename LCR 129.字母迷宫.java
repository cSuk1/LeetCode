/*
 * @lc app=leetcode.cn id=LCR 129 lang=java
 * @lcpr version=30116
 *
 * [LCR 129] 字母迷宫
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start

import java.util.ArrayList;

class Solution {
    public boolean wordPuzzle(char[][] grid, String target) {
        int height = grid.length;
        int width = grid[0].length;
        boolean[][] visited = new boolean[height][width];
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(grid[i][j] == target.charAt(0)){
                    if(dfs(target, 0, grid, i, j, height, width, visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    boolean dfs(String target, int index, char[][] grid, int m, int n, int h, int w, boolean[][] visited){
        if(index == target.length()){
            return true;
        }
        if(m < 0 || n < 0|| m >= h || n >= w || visited[m][n] || grid[m][n] != target.charAt(index)){
            return false;
        }else{
            visited[m][n] = true;
            boolean upper = dfs(target, index + 1, grid, m + 1, n, h, w, visited);
            if (upper) {
                visited[m][n] = false;
                return true;
            }
            boolean left = dfs(target, index + 1, grid, m, n + 1, h, w, visited);
            if (left) {
                visited[m][n] = false;
                return true;
            }
            boolean lower = dfs(target, index + 1, grid, m - 1, n, h, w, visited);
            if (lower) {
                visited[m][n] = false;
                return true;
            }
            boolean right = dfs(target, index + 1, grid, m, n - 1, h, w, visited);
            visited[m][n] = false;
            return upper || left || lower || right;
        }
    }
}
// @lc code=end

/*
 * // @lcpr case=start
 * // [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * // [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"SEE"\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * // [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCB"\n
 * // @lcpr case=end
 * 
 */
