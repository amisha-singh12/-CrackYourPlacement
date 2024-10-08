class Solution {
public:
    int minSwaps(string s) {
        int balance = 0;  // Keeps track of current balance between '[' and ']'
        int swaps = 0;    // Tracks the number of swaps needed

        // Traverse through the string
        for (char c : s) {
            if (c == '[') {
                balance++;  // Increase balance for '['
            } else {
                balance--;  // Decrease balance for ']'
            }

            // If balance is negative, it means there are more `]` than `[` so far
            if (balance < 0) {
                swaps++;       // We need a swap
                balance += 2;  // This simulates balancing the `]` with a future `[`
            }
        }

        return swaps;  // Return the total number of swaps needed
    }
};
