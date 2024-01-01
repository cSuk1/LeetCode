/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    bool hasAll(unordered_map<char, int> &has,
                unordered_map<char, int> &need)
    {
        for (auto &n : need)
        {
            if (has.find(n.first) == has.end())
            {
                return false;
            }
            else if (has[n.first] < n.second)
            {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t)
    {
        int left = 0, right = 0;
        string ret;
        unordered_map<char, int> has;
        unordered_map<char, int> need;
        vector<int> index;
        index.push_back(0);
        index.push_back(s.length() + 1);
        for (auto c : t)
        {
            need[c] = need.find(c) == need.end() ? 1 : need[c] + 1;
        }
        while (right <= s.length() && left <= right)
        {
            if (!hasAll(has, need))
            {
                has[s[right]] = has.find(s[right]) == has.end() ? 1 : has[s[right]] + 1;
                right++;
            }
            else
            {
                if (right - left < index[1] - index[0])
                {
                    index[0] = left;
                    index[1] = right;
                }
                left++;
                has[s[left - 1]]--;
            }
        }
        return index[1] - index[0] == s.length() + 1 ? ret : s.substr(index[0], index[1] - index[0]);
    }
};
// @lc code=end
