class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1; // A single element is always a valid subarray
        
        int inc = 1, dec = 1, maxLen = 1;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {  // Increasing
                inc++;
                dec = 1;  // Reset decreasing counter
            } 
            else if (nums[i] < nums[i - 1]) { // Decreasing
                dec++;
                inc = 1;  // Reset increasing counter
            } 
            else {  // If nums[i] == nums[i-1], reset both
                inc = 1;
                dec = 1;
            }
            maxLen = max(maxLen, max(inc, dec));  // Update max length found
        }
        
        return maxLen;
    }
};