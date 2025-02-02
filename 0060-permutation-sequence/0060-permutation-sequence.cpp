class Solution {
public:
    int count = 0;  // To track how many permutations we have generated
    string ans = ""; // Store the k-th permutation

    void solve(vector<int>& nums, vector<bool>& used, string& temp, int n, int k) {
        if (temp.size() == n) { // Base case: complete permutation
            count++;
            if (count == k) { // If it's the k-th permutation, store it
                ans = temp;
            }
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!used[i]) {  // If number is not used in current permutation
                used[i] = true;
                temp += to_string(nums[i]);  // Add number to permutation
                solve(nums, used, temp, n, k); // Recursive call
                
                if (!ans.empty()) return; // Stop recursion if answer found
                
                temp.pop_back(); // Backtrack: remove last character
                used[i] = false; // Mark number as unused
            }
        }
    }

    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++) nums.push_back(i); // Fill numbers 1 to n
        vector<bool> used(n, false); // Keep track of used numbers
        string temp = ""; // Current permutation
        
        solve(nums, used, temp, n, k);
        return ans;
    }
};

