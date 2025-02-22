class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);  // Start of stick
        cuts.push_back(n);  // End of stick
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int len = 2; len < m; ++len) {  // Gap-based DP
            for (int l = 0; l < m - len; ++l) {
                int r = l + len;
                dp[l][r] = INT_MAX;

                for (int k = l + 1; k < r; ++k) {
                    dp[l][r] = min(dp[l][r], cuts[r] - cuts[l] + dp[l][k] + dp[k][r]);
                }
            }
        }
        return dp[0][m - 1];
    }
};
