/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include "a_header.h"
// @lc code=start
class MyQueue
{
private:
    stack<int> s1;
    stack<int> s2;
    int size;

public:
    MyQueue()
    {
        size = 0;
    }

    void push(int x)
    {
        s1.push(x);
        size++;
    }

    int pop()
    {
        if (size == 0)
        {
            return -1;
        }
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ret = s2.top();
        s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        size--;
        return ret;
    }

    int peek()
    {
        if (size == 0)
        {
            return -1;
        }
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ret = s2.top();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ret;
    }

    bool empty()
    {
        return size == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
