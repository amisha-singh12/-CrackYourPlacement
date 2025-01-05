class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;  // Check if the input array is empty

        vector<int> unique_nums;    // New vector to store unique elements
        unique_nums.push_back(nums[0]); // Add the first element

        for (int i = 1; i < nums.size(); ++i) {
            // Add only if the current number is different from the last added unique number
            if (nums[i] != nums[i - 1]) {
                unique_nums.push_back(nums[i]);
            }
        }

        // Copy the unique elements back into the original array
        for (int i = 0; i < unique_nums.size(); ++i) {
            nums[i] = unique_nums[i];
        }

        return unique_nums.size(); // Return the size of the unique array
    }
};
