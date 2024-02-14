/*
 * @lc app=leetcode.cn id=LCR 122 lang=java
 * @lcpr version=30116
 *
 * [LCR 122] 路径加密
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
    public String pathEncryption(String path) {
        String result = "";
        for(int i=0;i<path.length();++i){
            if(path.charAt(i) == '.'){
                result += ' ';
            }else{
                result += path.charAt(i);
            }
        }
        return result;
    }
}
// @lc code=end



/*
// @lcpr case=start
// "a.aef.qerf.bb"\n
// @lcpr case=end

 */

