/*
 * @lc app=leetcode.cn id=LCR 125 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 125] 图书整理 II
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class CQueue
{
private:
    stack<int> r_books;
    stack<int> l_books;

public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        r_books.push(value);
    }

    int deleteHead()
    {
        if (l_books.empty())
        {
            if (r_books.empty())
            {
                return -1;
            }
            while (!r_books.empty())
            {
                l_books.push(r_books.top());
                r_books.pop();
            }
        }
        int ret = l_books.top();
        l_books.pop();
        return ret;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
// @lc code=end

/*
// @lcpr case=start
// ["BookQueue", "push", "push", "pop"][[], [1], [2], []]\n
// @lcpr case=end

 */
