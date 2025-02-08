class MyQueue {
private:
    stack<int> stack1; // Inbox stack
    stack<int> stack2; // Outbox stack
    
    // Helper function to move elements from stack1 to stack2 if stack2 is empty
    void transfer() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stack1.push(x); // Push to the inbox stack
    }
    
    int pop() {
        transfer(); // Transfer elements to stack2 if necessary
        int front = stack2.top(); // Get the front of the queue
        stack2.pop(); // Remove the front
        return front;
    }
    
    int peek() {
        transfer(); // Transfer elements to stack2 if necessary
        return stack2.top(); // Peek at the front of the queue
    }
    
    bool empty() {
        return stack1.empty() && stack2.empty(); // Queue is empty if both stacks are empty
    }
};
