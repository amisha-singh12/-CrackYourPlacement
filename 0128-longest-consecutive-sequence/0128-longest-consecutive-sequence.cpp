#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Insert all elements into a set to remove duplicates and sort
        set<int> unique_nums(nums.begin(), nums.end());

        int maxCount = 0;

        // Iterate over the set
        for (int num : unique_nums) {
            // Check if this number is the start of a sequence
            if (unique_nums.find(num - 1) == unique_nums.end()) {
                int currentNum = num;
                int count = 1;

                // Count consecutive numbers
                while (unique_nums.find(currentNum + 1) != unique_nums.end()) {
                    currentNum++;
                    count++;
                }

                maxCount = max(maxCount, count);
            }
        }

        return maxCount;
    }
};
