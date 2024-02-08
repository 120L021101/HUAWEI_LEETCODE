class MinStack {
private:
    vector<int> val_stack;
    vector<int> min_stack;
    decltype(val_stack.size()) size = 0;
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        val_stack.push_back(x);
        if (size)
            min_stack.push_back(min(x, min_stack[min_stack.size() - 1]));
        else
            min_stack.push_back(x);
        ++size;
    }
    
    void pop() {
        val_stack.pop_back();
        min_stack.pop_back();
        --size;
    }
    
    int top() {
        return val_stack[val_stack.size() - 1];
    }
    
    int getMin() {
        return min_stack[min_stack.size() - 1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */