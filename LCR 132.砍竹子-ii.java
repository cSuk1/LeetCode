/*
 * @lc app=leetcode.cn id=LCR 132 lang=java
 * @lcpr version=30116
 *
 * [LCR 132] 砍竹子 II
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
    public int cuttingBamboo(int n) {
        if(n < 3) {return 1;}
        if(n == 3) {return 2;}
        long res = 1;
        while(n > 4) {
            res *= 3;
            res %= 1000000007;
            n -= 3;
        }
        return (int)(n * res % 1000000007);
    }
}
// @lc code=end



/*
// @lcpr case=start
// 12\n
// @lcpr case=end

 */

