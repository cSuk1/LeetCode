/*
 * @lc app=leetcode.cn id=43 lang=java
 * @lcpr version=30116
 *
 * [43] 字符串相乘
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
    public String multiply(String num1, String num2) {
        int m = num1.length();
        int n = num2.length();
        // 保存每位相乘的结果
        int[] result = new int[m + n];

        // 从个位数开始逐位相乘
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // 相乘结果
                int mul = (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
                // 乘积的高位索引
                int p1 = i + j;
                // 乘积的低位索引
                int p2 = i + j + 1;

                // 加上相乘结果和原来的值
                int sum = mul + result[p2];
                // 个位数
                result[p2] = sum % 10;
                // 进位
                result[p1] += sum / 10;
            }
        }

        // 构建乘积字符串
        StringBuilder sb = new StringBuilder();
        for (int digit : result) {
            // 跳过前导0
            if (sb.length() == 0 && digit == 0) {
                continue;
            }
            sb.append(digit);
        }

        // 处理结果为0的情况
        if (sb.length() == 0) {
            return "0";
        }

        return sb.toString();
    }
}
// @lc code=end

/*
 * // @lcpr case=start
 * // "2"\n"3"\n
 * // @lcpr case=end
 * 
 * // @lcpr case=start
 * // "123"\n"456"\n
 * // @lcpr case=end
 * 
 */
