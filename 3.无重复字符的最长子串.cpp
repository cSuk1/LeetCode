/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> set;
        size_t ret = 0;
        int left = 0, right = 0;
        string tmp;
        while (right < s.size() && left <= right)
        {
            if (set.find(s[right]) == set.end())
            {
                tmp += s[right];
                set.insert(s[right]);
                ret = max(ret, tmp.length());
                cout << tmp << " len: " << tmp.length() << endl;
                right++;
            }
            else
            {
                while (set.find(s[right]) != set.end())
                {
                    set.erase(tmp[0]);
                    tmp.erase(0, 1);
                    left++;
                }
            }
        }
        return ret;
    }
};
// @lc code=end
