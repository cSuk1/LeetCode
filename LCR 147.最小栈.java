/*
 * @lc app=leetcode.cn id=LCR 147 lang=java
 * @lcpr version=30117
 *
 * [LCR 147] 最小栈
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class MinStack {
    private List<Integer> stack;
    private Map<Integer, Integer> map;
    private int size;
    private int index;

    /** initialize your data structure here. */
    public MinStack() {
        size = 0;
        index = -1;
        stack = new ArrayList<>();
        map = new HashMap<>();
    }

    public void push(int x) {
        stack.add(x);
        size++;
        if (index == -1 || x < stack.get(index)) {
            map.put(size - 1, index);
            index = size - 1;
        }
    }

    public void pop() {
        if (index == size - 1) {
            index = map.get(size - 1);
        }
        stack.remove(--size);
    }

    public int top() {
        return stack.get(size - 1);
    }

    public int getMin() {
        return stack.get(index);
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
// @lc code=end

/*
 * // @lcpr case=start
 * //
 * ["MinStack","push","push","push","getMin","pop","top","getMin"][[],[-2],[2],[
 * -3],[],[],[],[]]\n
 * // @lcpr case=end
 * 
 */
