class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Step 1: Create a set for allowed characters
        unordered_set<char> allowedSet(allowed.begin(), allowed.end());
        int consistentCount = 0;

        // Step 2: Check each word in words
        for (const string& word : words) {
            bool isConsistent = true;

            // Step 3: Check if all characters in the word are in allowedSet
            for (char ch : word) {
                if (allowedSet.find(ch) == allowedSet.end()) {
                    isConsistent = false;
                    break;
                }
            }

            // Step 4: If consistent, increment the count
            if (isConsistent) {
                consistentCount++;
            }
        }

        return consistentCount;
    }
};
