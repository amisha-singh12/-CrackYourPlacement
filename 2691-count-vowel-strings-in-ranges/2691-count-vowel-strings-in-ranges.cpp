class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // Vowel set for quick lookup
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        int n = words.size();
        vector<int> prefix(n, 0);
        
        // Build the prefix sum array
        for (int i = 0; i < n; ++i) {
            // Check if the word starts and ends with a vowel
            char first = words[i][0];
            char last = words[i].back();
            if (vowels.count(first) && vowels.count(last)) {
                prefix[i] = 1;
            }
            // Add to the cumulative count
            if (i > 0) {
                prefix[i] += prefix[i - 1];
            }
        }
        
        // Process queries
        vector<int> ans;
        for (auto& query : queries) {
            int li = query[0];
            int ri = query[1];
            if (li == 0) {
                ans.push_back(prefix[ri]);
            } else {
                ans.push_back(prefix[ri] - prefix[li - 1]);
            }
        }
        
        return ans;
    }
};
