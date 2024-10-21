#include <vector>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        // dutch national flag algorithm 
        // we simply are sorting based on comparison taking care of occurences.
        int low = 0, mid = 0, high = nums.size() - 1;
        
        while (mid <= high) {
            if (nums[mid] == 0) {
                std::swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                std::swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};