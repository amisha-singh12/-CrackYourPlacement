class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Sort the array to use the sliding window technique
        long long sum = 0;              // To store the sum of elements in the current window
        int left = 0, maxFreq = 1;      // Left pointer of the sliding window, and max frequency found
        
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right]; // Add the current element to the sum
            
            // Check if the current window is valid
            // If not, move the left pointer to shrink the window
            // Use long long for safe multiplication
            while (static_cast<long long>(nums[right]) * (right - left + 1) > sum + k) {
                sum -= nums[left]; // Subtract the element at the left pointer
                left++;            // Move the left pointer to the right
            }
            
            // Calculate the size of the valid window
            maxFreq = max(maxFreq, right - left + 1);
        }
        
        return maxFreq;
    }
};
