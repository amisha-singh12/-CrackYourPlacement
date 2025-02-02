class Solution {
public:
    vector<vector<string>> result;  // Stores final palindrome partitions

    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++, end--;
        }
        return true;
    }

    void backtrack(string &s, int start, vector<string> &path) {
        if (start == s.size()) {
            result.push_back(path); // Found a valid partition
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            if (isPalindrome(s, start, end)) {  // Check if s[start:end] is a palindrome
                path.push_back(s.substr(start, end - start + 1)); // Add to partition
                backtrack(s, end + 1, path);  // Recur for the next substring
                path.pop_back(); // Backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;  // Temporary list to store the current partition
        backtrack(s, 0, path);
        return result;
    }
};
