class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        
        for (int num : nums) {
            if (num <= first) {
                first = num;  // update the smallest number
            } else if (num <= second) {
                second = num;  // update the second smallest number
            } else {
                // if we find a number larger than both first and second
                return true;
            }
        }
        
        // no increasing triplet found
        return false;
    }
};
