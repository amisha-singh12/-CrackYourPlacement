class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        
        // Calculate the sum of the known rolls
        int sum_m = accumulate(rolls.begin(), rolls.end(), 0);
        
        // Calculate the total sum needed for all n + m rolls
        int total_sum = (n + m) * mean;
        
        // Calculate the sum of the missing rolls
        int sum_n = total_sum - sum_m;
        
        // Check if sum_n is within the valid range
        if (sum_n < n || sum_n > 6 * n) {
            return {};
        }
        
        // Create an array for the missing rolls
        vector<int> result(n, 1);
        
        // Distribute the remaining sum_n - n across the result array
        sum_n -= n;  // Since we have already allocated 1 to each roll
        
        // Distribute the remaining sum
        for (int i = 0; i < n && sum_n > 0; ++i) {
            int add = min(5, sum_n);  // We can add at most 5 (to make a roll at most 6)
            result[i] += add;
            sum_n -= add;
        }
        
        return result;
    }
};
