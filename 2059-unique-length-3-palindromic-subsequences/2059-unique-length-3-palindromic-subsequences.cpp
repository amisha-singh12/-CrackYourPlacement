class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> left(26, 0);   // Tracks which characters are seen on the left
        vector<int> right(26, 0); // Tracks character frequencies to the right
        
        // Initialize right array with character frequencies
        for (char c : s) {
            right[c - 'a']++;
        }
        
        // Use a 2D boolean array to track unique palindromes
        vector<vector<bool>> seen(26, vector<bool>(26, false));
        int count = 0;

        // Traverse the string, treating each character as the middle of a palindrome
        for (int i = 0; i < n; ++i) {
            right[s[i] - 'a']--; // Decrease the frequency of the current character in `right`
            
            // Check for all characters 'a' to 'z' as possible `a` in `a b a`
            for (int c = 0; c < 26; ++c) {
                if (left[c] > 0 && right[c] > 0 && !seen[c][s[i] - 'a']) {
                    seen[c][s[i] - 'a'] = true; // Mark this palindrome as seen
                    count++;
                }
            }
            
            left[s[i] - 'a']++; // Mark the current character as seen on the left
        }
        
        return count;
    }
};

