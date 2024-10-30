#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int candidate1 = 0, candidate2 = 0;

        // Step 1: Find candidates
        for (int num : nums) {
            if (count1 == 0 && num != candidate2) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0 && num != candidate1) {
                candidate2 = num;
                count2 = 1;
            } else if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        // Step 2: Verify candidates
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        // Step 3: Collect valid candidates
        vector<int> result;
        int threshold = nums.size() / 3;
        if (count1 > threshold) result.push_back(candidate1);
        if (count2 > threshold) result.push_back(candidate2);

        return result;
    }
};
