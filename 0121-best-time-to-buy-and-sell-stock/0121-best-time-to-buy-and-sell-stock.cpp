class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX; // Initialize minPrice to a very large value
        int maxProfit = 0; // Initialize maxProfit to 0
        
        for (int i = 0; i < prices.size(); i++) {
            // If the current price is less than minPrice, update minPrice
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            // Calculate the profit if we sell at the current price
            int profit = prices[i] - minPrice;
            // Update maxProfit if the current profit is higher
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
        
        return maxProfit; // Return the maximum profit found
    }
};
