class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0; // To track unbalanced '('
        int close_needed = 0; // To track needed ')'
        
        for (char c : s) {
            if (c == '(') {
                open++; // We expect a closing ')' for this '('
            } else { // c == ')'
                if (open > 0) {
                    open--; // We have a matching '(' for this ')'
                } else {
                    close_needed++; // We need an extra '(' before this ')'
                }
            }
        }
        
        // The total moves required are unmatched '(' + unmatched ')'
        return open + close_needed;
    }
};
