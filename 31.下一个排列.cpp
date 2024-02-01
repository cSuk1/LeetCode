/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    /**
     * 最大-递减序列
     * 最小-递增序列
     *
     * 所以本题的实质就是从右边开始向左遍历
     * 找到从右边开始的第一个递减的数n 下标为 i
     * 然后将n与右边大于n的最小数交换，
     * 这样新的序列不论下标 i 之后的数字排序如何，都大于原来的序列
     * 所以要让新序列是下一个序列，只需要让下标 i 之后的数字是从左往右递增的即可（最小）
     **/
    void nextPermutation(vector<int> &nums)
    {
        int find = -1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i + 1] > nums[i])
            {
                find = i;
                cout << find << endl;
                while (i + 1 < nums.size() && nums[i + 1] > nums[find])
                {
                    i++;
                }
                cout << i << endl;
                swap(nums[find], nums[i]);
                for (int j = find + 1; j < find + 1 + (nums.size() - find - 1) / 2; j++)
                {
                    swap(nums[j], nums[nums.size() + find + 1 - j - 1]);
                }
                return;
            }
        }
        if (find == -1)
        {
            for (int i = 0; i < nums.size() / 2; i++)
            {
                swap(nums[i], nums[nums.size() - i - 1]);
            }
        }
    }
};

// @lc code=end
