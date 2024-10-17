#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Create a frequency map
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Use a priority queue (max-heap) to sort by frequency and handle tie by value
        // The lambda compares by frequency (greater frequency comes first) and then by value (lower value comes first).
        auto comp = [&](pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first > b.first; // Ascending order if frequencies are the same
            }
            return a.second < b.second;  // Descending order by frequency
        };
        
        // Max-heap to store elements by frequency and value
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        
        // Push all elements into the priority queue
        for (auto& entry : freq) {
            pq.push({entry.first, entry.second});
        }
        
        // Step 3: Extract the top k elements
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        
        return result;
    }
};
