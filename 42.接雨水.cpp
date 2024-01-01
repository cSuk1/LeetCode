/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include "a_header.h"
// @lc code=start
// class Solution
// {
// public:
//     int volume(vector<int> &height, int start, int end, int h)
//     {
//         int ret = 0;
//         for (size_t i = start + 1; i < end; i++)
//         {
//             int diff = h - height[i];
//             ret += (diff > 0) ? diff : 0;
//             height[i] = (diff > 0) ? h : height[i];
//         }
//         return ret;
//     }

//     int trap(vector<int> &height)
//     {
//         int pre = 0, nx = height.size() - 1, res = 0;
//         unordered_set<int> layers;
//         layers.insert(0);
//         while (pre < nx)
//         {
//             if (height[pre] <= height[nx])
//             {
//                 if (layers.find(height[pre]) == layers.end())
//                 {
//                     res += volume(height, pre, nx, height[pre]);
//                     layers.insert(height[pre]);
//                 }
//                 pre++;
//             }
//             else
//             {
//                 if (layers.find(height[nx]) == layers.end())
//                 {
//                     res += volume(height, pre, nx, height[nx]);
//                     layers.insert(height[nx]);
//                 }
//                 nx--;
//             }
//         }
//         return res;
//     }
// };
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
        {
            return 0;
        }

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] > leftMax)
                {
                    leftMax = height[left];
                }
                else
                {
                    water += leftMax - height[left];
                }
                left++;
            }
            else
            {
                if (height[right] > rightMax)
                {
                    rightMax = height[right];
                }
                else
                {
                    water += rightMax - height[right];
                }
                right--;
            }
        }

        return water;
    }
};
// @lc code=end
