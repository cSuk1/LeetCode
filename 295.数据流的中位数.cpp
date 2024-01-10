/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */
#include "a_header.h"
// @lc code=start
class MedianFinder
{
private:
    priority_queue<int, vector<int>, less<int>> Min;
    priority_queue<int, vector<int>, greater<int>> Max;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (Min.empty() || num <= findMedian())
        {
            Min.push(num);
            if (Max.size() + 1 < Min.size())
            {
                Max.push(Min.top());
                Min.pop();
            }
        }
        else
        {
            Max.push(num);
            if (Max.size() > Min.size() + 1)
            {
                Min.push(Max.top());
                Max.pop();
            }
        }
    }

    double findMedian()
    {
        if (Max.size() == Min.size())
        {
            return (Max.top() + Min.top()) / 2.0;
        }
        else if (Max.size() > Min.size())
        {
            return Max.top();
        }
        else
        {
            return Min.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
