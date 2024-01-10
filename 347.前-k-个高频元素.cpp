/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        unordered_map<int, int> frequent;
        for (auto &num : nums)
        {
            frequent[num]++;
        }
        for (auto &it : frequent)
        {
            cout << it.first << "=" << it.second << " ";
        }
        cout << endl;
        vector<int> ret;
        for (auto &it : frequent)
        {
            if (ret.size() == k)
            {
                if (it.second > frequent[ret[0]])
                {
                    pop_heap(ret.begin(), ret.end(), [&frequent](auto &a, auto &b)
                             { return frequent[a] > frequent[b]; });
                    ret.pop_back();
                    ret.push_back(it.first);
                    push_heap(ret.begin(), ret.end(), [&frequent](auto &a, auto &b)
                              { return frequent[a] > frequent[b]; });
                }
            }
            else
            {
                ret.push_back(it.first);
                push_heap(ret.begin(), ret.end(), [&frequent](auto &a, auto &b)
                          { return frequent[a] > frequent[b]; });
            }
        }
        return ret;
    }
};
// @lc code=end
