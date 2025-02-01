class Solution {
public:
    vector<vector<int>> ans; // Store valid combinations

    void solve(vector<int>& candidates, int target, vector<int>& v, int sum, int index) {
        // Base Case: If sum equals target, store the combination
        if (sum == target) {
            ans.push_back(v);
            return;
        }

        // Iterate through the candidates
        for (int i = index; i < candidates.size(); i++) {
            // Skip duplicates to avoid repeated combinations
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            // If adding this number exceeds target, stop (since the array is sorted)
            if (sum + candidates[i] > target) break;

            // Choose the current number
            v.push_back(candidates[i]);

            // Move to the next index (each number is used at most once)
            solve(candidates, target, v, sum + candidates[i], i + 1);

            // Backtrack: Remove last element
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        vector<int> v;  // Temporary vector for storing combinations
        solve(candidates, target, v, 0, 0);
        return ans;
    }
};

