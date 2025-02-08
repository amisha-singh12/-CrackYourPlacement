#include <stack>
#include <iostream>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;

        for (char ch : s) {
            // Push opening brackets onto the stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            // Handle closing brackets
            else {
                // If stack is empty, there is no matching opening bracket
                if (st.empty()) return false;

                char top = st.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {
                    st.pop(); // Valid match, remove top
                } else {
                    return false; // Mismatch found
                }
            }
        }

        // Stack should be empty if all brackets are matched
        return st.empty();
    }
};