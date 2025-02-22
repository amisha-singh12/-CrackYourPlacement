class Solution {
public:
    vector<vector<int>> t;  // Use dynamic vector instead of static array

    int solve(const vector<int>& cuts, int l, int r) {
        if (r - l < 2) return 0;  // No cuts possible

        if (t[l][r] != -1) return t[l][r];  // Memoized result

        int result = INT_MAX;
        for (int index = l + 1; index < r; index++) {
            int cost = (cuts[r] - cuts[l]) + solve(cuts, l, index) + solve(cuts, index, r);
            result = min(result, cost);
        }

        return t[l][r] = result;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        t.assign(m, vector<int>(m, -1));  // Resize memoization table

        return solve(cuts, 0, m - 1);
    }
};
