class Solution {
public:
    // Function to calculate how many numbers start with the prefix
    long countSteps(long curr, long n) {
        long steps = 0;
        long first = curr;
        long last = curr;
        
        while (first <= n) {
            steps += min(n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }
        
        return steps;
    }

    int findKthNumber(int n, int k) {
        long curr = 1;
        k--;  // We start from 1, so reduce k by 1 to handle zero-based indexing
        
        while (k > 0) {
            long steps = countSteps(curr, n);
            if (steps <= k) {
                // Move to the next number at the same level
                curr++;
                k -= steps;
            } else {
                // Move to the next level (go deeper into the prefix tree)
                curr *= 10;
                k--;
            }
        }
        
        return curr;
    }
};
