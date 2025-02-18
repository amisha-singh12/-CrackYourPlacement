class Solution {
public:
// top down approach (recur + memoization)
    unordered_map<int, pair<int, int>> memo;
    pair<int, int> helper(vector<int>& nums, int i) {
        if (i == 0) return {nums[0], nums[0]};
        if (memo.find(i) != memo.end()) return memo[i];

        auto [prev_max, prev_min] = helper(nums, i - 1);

        int cur_max = max({nums[i], prev_max * nums[i], prev_min * nums[i]});
        int cur_min = min({nums[i], prev_max * nums[i], prev_min * nums[i]});

        return memo[i] = {cur_max, cur_min};
    }

    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int result = nums[0];

        for (int i = 0; i < n; i++) {
            auto [max_p, min_p] = helper(nums, i);
            result = max(result, max_p);
        }

        return result;
    }
};

