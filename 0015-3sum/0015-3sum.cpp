class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        // Sort the array first
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = nums.size() - 1;
            
            // Use two-pointer technique to find pairs that sum to -nums[i]
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Move pointers and skip duplicates
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } else if (sum < 0) {
                    // If sum is less than 0, we need to increase it by moving the left pointer to the right
                    left++;
                } else {
                    // If sum is greater than 0, we need to decrease it by moving the right pointer to the left
                    right--;
                }
            }
        }
        
        return result;
    }
};
