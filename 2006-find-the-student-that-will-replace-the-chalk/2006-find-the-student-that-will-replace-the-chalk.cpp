class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // Step 1: Calculate the total chalk usage in one round
        long long chalk_sum = 0;
        for (int ch : chalk) {
            chalk_sum += ch;
        }

        // Step 2: Reduce k modulo the total chalk usage in one round
        k %= chalk_sum;

        // Step 3: Find the student who will replace the chalk
        for (int i = 0; i < chalk.size(); ++i) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }

        return 0; // This line will never be reached
    }
};
