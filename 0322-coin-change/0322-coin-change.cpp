class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Initialize DP array
        vector<int> dp(amount + 1, INT_MAX - 1); // Use INT_MAX - 1 to avoid overflow
        dp[0] = 0; // Base case: 0 coins are needed for sum = 0

        // Iterate through all coins
        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }

        // If dp[sum] is still INT_MAX - 1, it means sum is unreachable
        return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
    }
};
