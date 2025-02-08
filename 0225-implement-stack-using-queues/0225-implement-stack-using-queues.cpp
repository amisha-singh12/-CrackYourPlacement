#include <queue>

class MyStack {
private:
    std::queue<int> q1, q2;  // Two queues for stack simulation

public:
    MyStack() {}

    // Push operation
    void push(int x) {
        q2.push(x);  // Step 1: Push to temporary queue

        // Step 2: Transfer all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: Swap q1 and q2 so that q1 always contains the stack elements
        std::swap(q1, q2);
    }

    // Pop operation
    int pop() {
        if (q1.empty()) return -1;  // Stack is empty
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    // Top operation
    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }

    // Check if stack is empty
    bool empty() {
        return q1.empty();
    }
};
