class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // Step 1: Calculate the total sum of the array
        long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        // Step 2: Find the target remainder that needs to be removed
        int target = totalSum % p;
        if (target == 0) return 0;  // If already divisible by p, return 0

        // Step 3: Use prefix sums and a hash map to find the smallest subarray
        unordered_map<int, int> prefixModMap;
        prefixModMap[0] = -1;  // Initial prefix sum of 0 at index -1
        long prefixSum = 0;
        int minLength = nums.size();  // Initialize to max possible size

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int currentMod = prefixSum % p;

            // Find the required previous prefix sum that would give a subarray with sum = target
            int requiredMod = (currentMod - target + p) % p;

            if (prefixModMap.find(requiredMod) != prefixModMap.end()) {
                // If found, calculate the length of the subarray to remove
                minLength = min(minLength, i - prefixModMap[requiredMod]);
            }

            // Store the current prefix sum modulo and its index
            prefixModMap[currentMod] = i;
        }

        // Step 4: Return the result
        return (minLength == nums.size()) ? -1 : minLength;
    }
};
