class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // creating frequency map
        unordered_map<int , int > freq;
        for(int num : nums) {
            freq[num]++;
        }
        // storing frequency map in vector of pairs (element , frequnecy)
        vector<pair<int , int >> freqVector; 
        // auto& automatically deduces the type of entry based on the type of elements in freq, 
        // const ensures that the entry is not modified during iteration (you cannot change the key or value).   
        for (const auto& entry : freq) {
            freqVector.push_back(entry);
        }
        // sort the vector by frequnecy
        sort(freqVector.begin(), freqVector.end() , [] (pair<int , int> & a , pair<int , int> &b) {
            if(a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b .second;
        });

         // Step 4: Collect the top k elements
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqVector[i].first);
        }
        
        return result;
    }
};