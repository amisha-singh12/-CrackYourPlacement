class CustomStack {
private:
    vector<int> stack;
    int maxSize;

public:
    // Constructor initializes the stack with a maximum size
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    // Adds x to the top of the stack if the stack has not reached the maxSize
    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }
    
    // Pops and returns the top of the stack, or -1 if the stack is empty
    int pop() {
        if (stack.empty()) {
            return -1;
        }
        int top = stack.back();
        stack.pop_back();
        return top;
    }
    
    // Increments the bottom k elements by val, if less than k elements, increment all
    void increment(int k, int val) {
        int limit = min(k, (int)stack.size());
        for (int i = 0; i < limit; i++) {
            stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
