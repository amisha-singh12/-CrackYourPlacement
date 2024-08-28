#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> modCount;
        modCount[0] = 1;  // Initializing with the base case
        
        int cumulativeSum = 0;
        int result = 0;
        
        for (int num : nums) {
            cumulativeSum += num;
            
            int mod = cumulativeSum % k;
            if (mod < 0) {
                mod += k;  // Handling negative modulo to always keep it in the range [0, k-1]
            }
            
            if (modCount.find(mod) != modCount.end()) {
                result += modCount[mod];
            }
            
            modCount[mod]++;
        }
        
        return result;
    }
};
