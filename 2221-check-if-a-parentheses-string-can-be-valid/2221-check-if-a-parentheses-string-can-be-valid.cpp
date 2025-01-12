#include <iostream>
#include <string>
using namespace std;

class Solution{
public:

bool canBeValid(string s, string locked) {
    int n = s.length();
    
    // If the length of the string is odd, it cannot be valid
    if (n % 2 != 0) return false;

    // Left-to-right traversal
    int minOpen = 0, maxOpen = 0;
    for (int i = 0; i < n; ++i) {
        if (locked[i] == '1') {
            // Fixed character
            if (s[i] == '(') {
                minOpen++;
                maxOpen++;
            } else { // s[i] == ')'
                minOpen--;
                maxOpen--;
            }
        } else {
            // Wildcard: Can be '(' or ')'
            minOpen--;
            maxOpen++;
        }

        // Minimum open parentheses cannot be negative
        if (minOpen < 0) minOpen = 0;

        // If maximum open parentheses is negative, it's invalid
        if (maxOpen < 0) return false;
    }

    // Right-to-left traversal (not necessary if minOpen == 0 already)
    return minOpen == 0;
 }
};
