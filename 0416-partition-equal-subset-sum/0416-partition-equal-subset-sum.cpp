class Solution {
public:
    int n;
    int dp[201][10001];  // Assuming constraints: n ≤ 200, target ≤ 10^4

    bool solve(vector<int>& nums, int i, int target) {
        if (target == 0) return true;
        if (i >= n || target < 0) return false;
        
        if (dp[i][target] != -1) return dp[i][target];  // Use memoized result

        // Try including or excluding the current number
        bool take = solve(nums, i + 1, target - nums[i]);
        bool skip = solve(nums, i + 1, target);

        return dp[i][target] = take || skip;
    }

    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        
        memset(dp, -1, sizeof(dp));  // Initialize entire dp array with -1

        return solve(nums, 0, target);
    }
};

