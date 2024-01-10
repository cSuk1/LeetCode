/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include "a_header.h"
// @lc code=start
class MinStack
{
private:
    int index;
    int nums;
    vector<pair<int, int>> stack;

public:
    MinStack()
    {
        nums = 0;
        index = -1;
    }

    void push(int val)
    {
        nums++;
        stack.push_back(make_pair(index, val));
        index = index == -1 ? 0 : (stack[index].second < val ? index : nums - 1);
    }

    void pop()
    {
        if (nums > 0)
        {
            if (nums == index + 1)
            {
                index = stack[index].first;
            }
            nums--;
            stack.pop_back();
        }
    }

    int top()
    {
        if (nums > 0)
            return stack[nums - 1].second;
        else
            return INT_MAX;
    }

    int getMin()
    {
        if (nums > 0)
            return stack[index].second;
        else
            return INT_MAX;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
