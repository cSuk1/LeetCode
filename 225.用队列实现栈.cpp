/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include "a_header.h"
// @lc code=start
class MyStack
{
private:
    deque<int> q;
    int size;

public:
    MyStack()
    {
        size = 0;
    }

    void push(int x)
    {
        size++;
        q.push_back(x);
    }

    int pop()
    {
        if (size == 0)
        {
            return -1;
        }
        int ret = q.back();
        q.pop_back();
        size--;
        return ret;
    }

    int top()
    {
        return q.back();
    }

    bool empty()
    {
        return size == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
