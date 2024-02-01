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
    bool cover(unordered_map<char, int> &need, unordered_map<char, int> &has)
    {
        for (auto &pr : need)
        {
            if (has.find(pr.first) == has.end())
            {
                return false;
            }
            if (has[pr.first] < pr.second)
            {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t)
    {
        unordered_map<char, int> need;
        unordered_map<char, int> has;
        int index = 0, len = s.length();
        bool find = false;
        for (char &ch : t)
        {
            need[ch]++;
        }
        if (need.find(s[0]) != need.end())
        {
            has[s[0]]++;
        }
        int left = 0, right = 1;
        while (left < right && right <= s.size())
        {
            // 如果完全包含
            if (cover(need, has))
            {
                find = true;
                if (right - left < len)
                {
                    index = left;
                    len = right - left;
                }
                if (has.find(s[left]) != has.end())
                {
                    has[s[left]]--;
                }
                left++;
            }
            else
            {
                if (need.find(s[right]) != need.end())
                {
                    has[s[right]]++;
                }
                right++;
            }
        }
        return find ? s.substr(index, len) : "";
    }
};
// @lc code=end
