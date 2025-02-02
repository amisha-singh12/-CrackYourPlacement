class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            vector<int> sorted(n); // Corrected allocation

            // Rotating the array
            int index = 0;
            for (int j = i; j < n; j++) {
                sorted[index++] = nums[j];
            }
            for (int j = 0; j < i; j++) {
                sorted[index++] = nums[j];
            }

            // Checking if sorted
            bool isSorted = true;
            for (int k = 0; k < n - 1; k++) {  // Avoid out-of-bounds
                if (sorted[k] > sorted[k + 1]) {
                    isSorted = false;
                    break;
                }
            }

            if (isSorted) return true;  // Found a valid rotation
        }

        return false; // No valid rotation found
    }
};
