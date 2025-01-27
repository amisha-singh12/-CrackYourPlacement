class Solution {
public:
    void generateSubsets(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current); // Add the current subset to the result

        for (int i = index; i < nums.size(); i++) {
            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1]) continue;

            // Include the current element in the subset
            current.push_back(nums[i]);

            // Recurse to the next element
            generateSubsets(nums, i + 1, current, result);

            // Backtrack (remove the last added element)
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        // Sort the input to handle duplicates easily
        sort(nums.begin(), nums.end());

        // Start generating subsets
        generateSubsets(nums, 0, current, result);

        return result;
    }
};
