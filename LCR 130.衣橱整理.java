/*
 * @lc app=leetcode.cn id=LCR 130 lang=java
 * @lcpr version=30116
 *
 * [LCR 130] 衣橱整理
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start

import java.util.Queue;

class Solution {
    public int wardrobeFinishing(int m, int n, int cnt) {
        int result = 1;
        Queue<int[]> queue = new LinkedList<int[]>();
        queue.add(new int[]{0, 0});
        boolean[][] visited = new boolean[m][n];
        visited[0][0] = true;
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int curM = cur[0], curN = cur[1];
            if (curM + 1 < m && get(curM + 1) + get(curN) <= cnt && !visited[curM + 1][curN]) {
                queue.add(new int[]{curM + 1, curN});
                visited[curM + 1][curN] = true;
                result++;
            }
            if (curN + 1 < n && get(curM) + get(curN + 1) <= cnt && !visited[curM][curN + 1]) {
                queue.add(new int[]{curM, curN + 1});
                visited[curM][curN + 1] = true;
                result++;
            }
        }
        return result;
    }

    private int get(int x) {
        int res = 0;
        while (x != 0) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }
}
// @lc code=end



/*
// @lcpr case=start
// 4\n7\n5\n
// @lcpr case=end

 */

