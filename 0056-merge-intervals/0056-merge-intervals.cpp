#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: Sort intervals by their start times
        sort(intervals.begin(), intervals.end());
        
        // Step 2: Initialize a result vector to store merged intervals
        vector<vector<int>> merged;
        
        // Step 3: Iterate through sorted intervals
        for (const auto& interval : intervals) {
            // If merged is empty or there's no overlap, add the interval
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                // If there's an overlap, merge the intervals by updating the end time
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        
        return merged;
    }
};
