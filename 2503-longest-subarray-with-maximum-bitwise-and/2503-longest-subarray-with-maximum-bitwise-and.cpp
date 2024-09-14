class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Step 1: Find the maximum number in the array
        int max_num = *max_element(nums.begin(), nums.end());
        
        // Step 2: Find the longest subarray with all elements equal to max_num
        int longest = 0;
        int current_length = 0;
        
        for (int num : nums) {
            if (num == max_num) {
                current_length++;
                longest = max(longest, current_length);
            } else {
                current_length = 0;  // Reset when the number is not max_num
            }
        }
        
        return longest;
    }
};
