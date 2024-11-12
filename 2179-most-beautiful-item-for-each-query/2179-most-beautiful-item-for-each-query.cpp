#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> maximumBeauty(std::vector<std::vector<int>>& items, std::vector<int>& queries) {
        // Step 1: Sort items by price
        std::sort(items.begin(), items.end());
        
        // Step 2: Precompute maximum beauty for each price
        std::vector<std::pair<int, int>> priceToBeauty;
        int maxBeauty = 0;
        for (const auto& item : items) {
            int price = item[0];
            int beauty = item[1];
            maxBeauty = std::max(maxBeauty, beauty);
            priceToBeauty.push_back({price, maxBeauty});
        }
        
        // Step 3: Sort queries with their original indices
        int n = queries.size();
        std::vector<std::pair<int, int>> queryWithIndex(n);
        for (int i = 0; i < n; ++i) {
            queryWithIndex[i] = {queries[i], i};
        }
        std::sort(queryWithIndex.begin(), queryWithIndex.end());
        
        // Step 4: Answer each query by binary search
        std::vector<int> answer(n, 0);
        int idx = 0;
        for (const auto& [query, originalIndex] : queryWithIndex) {
            // Move idx to the last item with price <= query
            while (idx < priceToBeauty.size() && priceToBeauty[idx].first <= query) {
                ++idx;
            }
            // If idx is positive, we have at least one item with price <= query
            if (idx > 0) {
                answer[originalIndex] = priceToBeauty[idx - 1].second;
            }
        }
        
        return answer;
    }
};
