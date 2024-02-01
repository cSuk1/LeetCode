/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    vector<string> fullJustify(vector<string> &words,
                               int maxWidth)
    {
        vector<string> ret;
        vector<string> tmp;
        int tmp_len = 0;
        int word_count = 0;
        for (string &word : words)
        {
            tmp_len += word.length();
            // 如果加上当前单词后，长度大于最大宽度，说明需要换行
            if (tmp_len + word_count > maxWidth)
            {
                int space_count =
                    maxWidth - tmp_len + word.length() - tmp.size() + 1;
                string line = "";
                if (tmp.size() == 1)
                {
                    line += tmp[0];
                    line += string(maxWidth - line.length(), ' ');
                }
                else
                {
                    int left = space_count % (tmp.size() - 1);
                    int every = space_count / (tmp.size() - 1);
                    for (size_t i = 0; i < tmp.size(); i++)
                    {
                        if (i < left)
                        {
                            line += tmp[i] + " ";
                            fill_n(back_inserter(line), every + 1, ' ');
                        }
                        else if (i == tmp.size() - 1)
                        {
                            line += tmp[i];
                        }
                        else
                        {
                            line += tmp[i] + " ";
                            fill_n(back_inserter(line), every, ' ');
                        }
                    }
                    if (line.length() < maxWidth)
                    {
                        line += string(maxWidth - line.length(), ' ');
                    }
                }
                ret.push_back(line);

                tmp.clear();
                tmp.push_back(word);
                tmp_len = word.length();
                word_count = 1;
            }
            // 如果加上当前单词，包括空格正好满一行
            else if (tmp_len + word_count == maxWidth)
            {
                tmp.push_back(word);
                string line = "";
                for (string &str : tmp)
                {
                    line += str + " ";
                }
                line.pop_back();
                ret.push_back(line);

                tmp.clear();
                tmp_len = 0;
                word_count = 0;
            }
            // 否则将当前单词纳入当前行
            else
            {
                tmp.push_back(word);
                word_count++;
            }
        }
        // 处理最后一行
        if (tmp.size() > 0)
        {
            string line = "";
            for (string &str : tmp)
            {
                line += str + " ";
            }
            line.pop_back();
            if (line.length() < maxWidth)
            {
                line += string(maxWidth - line.length(), ' ');
            }
            ret.push_back(line);
        }
        return ret;
    }
};
// @lc code=end
