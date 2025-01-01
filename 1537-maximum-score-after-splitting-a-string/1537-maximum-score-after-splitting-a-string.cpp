class Solution {
public:
    int maxScore(string s) {
        int totalOnes = 0;
        int leftZeros = 0;
        int maxScore = 0;

        // Calculate the total number of '1's in the string
        for (char c : s) {
            if (c == '1') {
                totalOnes++;
            }
        }

        int rightOnes = totalOnes;

        // Iterate through the string, considering all valid splits
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0') {
                leftZeros++;
            } else {
                rightOnes--;
            }

            // Calculate the score for the current split
            int score = leftZeros + rightOnes;

            // Update the maximum score if needed
            maxScore = std::max(maxScore, score);
        }

        return maxScore;
    }
};
