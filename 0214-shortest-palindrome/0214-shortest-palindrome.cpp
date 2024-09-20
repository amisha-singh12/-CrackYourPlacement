class Solution {
public:
    string shortestPalindrome(string s) {
        // Reverse the string 's' to get the reversed string
        string rev_s = string(s.rbegin(), s.rend());
        
        // Concatenate original string 's', a special character '#', and the reversed string 'rev_s'
        string concat = s + "#" + rev_s;
        
        // Initialize the KMP table (Longest Prefix Suffix table)
        int n = concat.size();
        vector<int> lps(n, 0);
        
        // Build the KMP table
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            
            // Adjust 'j' until we find a match or reduce 'j' to 0
            while (j > 0 && concat[i] != concat[j]) {
                j = lps[j - 1];
            }
            
            // If there is a match, increment 'j'
            if (concat[i] == concat[j]) {
                j++;
            }
            lps[i] = j;
        }
        
        // The last value of the LPS array gives us the length of the longest palindrome prefix
        int longest_palindrome_prefix_length = lps[n - 1];
        
        // Append the rest of the reversed string to the front of the original string
        return rev_s.substr(0, s.size() - longest_palindrome_prefix_length) + s;
    }
};
