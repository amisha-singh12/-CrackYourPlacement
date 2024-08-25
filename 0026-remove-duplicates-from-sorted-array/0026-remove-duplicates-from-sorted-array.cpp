class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // If the input array is empty, return 0
        
        int i = 0; // Initialize the first pointer
        
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) { // When a new unique element is found
                i++; // Increment the index for unique elements
                nums[i] = nums[j]; // Update the position of the next unique element
            }
        }
        
        return i + 1; // Return the count of unique elements
    }
};
