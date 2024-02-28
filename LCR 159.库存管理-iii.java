/*
 * @lc app=leetcode.cn id=LCR 159 lang=java
 * @lcpr version=30117
 *
 * [LCR 159] 库存管理 III
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
    private void quickSort(int left, int right, int[] stock){
        if(left >= right){
            return;
        }
        int start = left;
        int end = right;
        int index = left;
        int indexNum;
        while(left < right){
            indexNum = stock[index];
            if(index == left){
                if(stock[right] < indexNum){
                    stock[left] = stock[left] ^ stock[right];
                    stock[right] = stock[left] ^ stock[right];
                    stock[left] = stock[left] ^ stock[right];
                    index = right;
                    left++;
                }else{
                    right--;
                }
            }else if(index == right){
                if(stock[left] > indexNum){
                    stock[left] = stock[left] ^ stock[right];
                    stock[right] = stock[left] ^ stock[right];
                    stock[left] = stock[left] ^ stock[right];
                    index = left;
                    right--;
                }else{
                    left++;
                }
            }
        }
        quickSort(start, left-1, stock);
        quickSort(left+1, end, stock);
    }

    public int[] inventoryManagement(int[] stock, int cnt) {
        quickSort(0, stock.length - 1, stock);
        return Arrays.copyOfRange(stock, 0, cnt);
    }
}
// @lc code=end



/*
// @lcpr case=start
// [2,5,7,4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [0,2,3,6]\n2\n
// @lcpr case=end

 */

