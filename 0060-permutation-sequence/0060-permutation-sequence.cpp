class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact = 1;
        
        // Initialize the numbers and compute (n-1)!
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
            fact *= i;  // Compute n!
        }

        k--;  // Convert k to 0-based index
        string result;
        
        // Compute each digit of the permutation
        for (int i = n; i >= 1; i--) {
            fact /= i;  // Compute (i-1)!
            int index = k / fact;
            result += to_string(nums[index]);  // Select the number
            nums.erase(nums.begin() + index);  // Remove used number
            k %= fact;  // Reduce k
        }
        
        return result;
    }
};
