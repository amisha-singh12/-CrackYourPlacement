class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> result;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue; // Skip comparing the same word
                if (words[i].find(words[j]) != string::npos) {
                    // Check if words[j] is already in the result
                    if (std::find(result.begin(), result.end(), words[j]) == result.end()) {
                        result.push_back(words[j]);
                    }
                }
            }
        }

        return result;
    }
};
