class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        
        for (char c : s) {
            if (!stk.empty() && 
                ((stk.top() == 'A' && c == 'B') || (stk.top() == 'C' && c == 'D'))) {
                stk.pop(); // Remove the matching AB or CD
            } else {
                stk.push(c); // Otherwise, add the character to the stack
            }
        }
        
        return stk.size(); // The size of the stack is the minimum possible length
    }
};
