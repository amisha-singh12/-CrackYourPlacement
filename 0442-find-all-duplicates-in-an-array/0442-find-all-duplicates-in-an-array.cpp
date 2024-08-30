#include <vector>
#include <cmath>
#pragma GCC optimize ("O2")

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        std::vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int pos = std::abs(nums[i]) - 1;
            if(nums[pos] < 0) {
                res.push_back(pos + 1);
            }
            nums[pos] = -nums[pos];
        }
        return res;
    }
};




    