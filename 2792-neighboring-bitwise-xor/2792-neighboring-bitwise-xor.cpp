class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();

        // Helper function to check validity for a given starting value of original[0]
        auto isValid = [&](int start) {
            vector<int> original(n);
            original[0] = start;

            // Compute the original array using derived
            for (int i = 1; i < n; i++) {
                original[i] = original[i - 1] ^ derived[i - 1];
            }

            // Check the circular condition
            return (original[n - 1] ^ original[0]) == derived[n - 1];
        };

        // Check for both possible starting values of original[0]: 0 and 1
        return isValid(0) || isValid(1);
    }
};
