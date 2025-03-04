#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        
        // Ignore leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Edge case: Empty string after removing spaces
        if (i == n) return 0;

        // Handle sign
        int sign = 1;
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Convert digits to integer
        long ans = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check for overflow
            if (ans > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return (int)(sign * ans);
    }
};
