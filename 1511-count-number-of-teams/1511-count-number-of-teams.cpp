class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        long long teams = 0;  // Keep this as int because it won't overflow in the constraints

        for (int i = 1; i < n - 1; i++) {
            int countrightsmaller = 0, countleftsmaller = 0;
            int countrightlarger = 0, countleftlarger = 0;

            // Count elements on the left side
            for (int j = 0; j < i; j++) {
                if (rating[j] > rating[i])
                    countleftlarger++;
                else if (rating[j] < rating[i])
                    countleftsmaller++;
            }

            // Count elements on the right side
            for (int k = i + 1; k < n; k++) {
                if (rating[k] > rating[i])
                    countrightlarger++;
                else if (rating[k] < rating[i])
                    countrightsmaller++;
            }

            // Calculate number of valid teams
            teams += (countrightsmaller * countleftlarger) + (countrightlarger * countleftsmaller);
        }

        return teams;
    }
};
