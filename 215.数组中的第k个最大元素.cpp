/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    // 下沉操作，将元素下沉到合适的位置，使得以该元素为根的子树满足堆的性质
    void heapify(std::vector<int> &nums, int size, int index)
    {
        int largest = index;       // 当前节点为最大值
        int left = 2 * index + 1;  // 左子节点的索引
        int right = 2 * index + 2; // 右子节点的索引
        // 比较左子节点和当前节点的值
        if (left < size && nums[left] > nums[largest])
        {
            largest = left;
        }
        // 比较右子节点和当前节点的值
        if (right < size && nums[right] > nums[largest])
        {
            largest = right;
        }
        // 如果最大值不是当前节点，则交换它们，并继续向下调整
        if (largest != index)
        {
            std::swap(nums[index], nums[largest]);
            heapify(nums, size, largest);
        }
    }

    // 堆排序算法
    void heapSort(std::vector<int> &nums)
    {
        int size = nums.size();
        // 构建初始堆，从最后一个非叶子节点开始，依次进行下沉操作
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(nums, size, i);
        }
        // 重复执行以下操作，直到堆中只剩下一个元素
        for (int i = size - 1; i > 0; i--)
        {
            // 将堆顶元素（最大值）与堆中的最后一个元素交换位置
            std::swap(nums[0], nums[i]);
            // 对剩余元素进行堆调整，使其满足堆的性质
            heapify(nums, i, 0);
        }
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        heapSort(nums);
        return nums[nums.size() - k];
    }
};
// @lc code=end
