/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &words)
    {
        vector<vector<string>> ret;
        int cnt = 0;
        unordered_map<string, int> mp;
        int iter = 0;
        for (string word : words)
        {
            sort(word.begin(), word.end());
            if (mp.find(word) == mp.end())
            {
                mp[word] = cnt++;
                ret.push_back({words[iter]});
            }
            else
            {
                ret[mp[word]].push_back(words[iter]);
            }
            iter++;
        }
        return ret;
    }
};
// @lc code=end
