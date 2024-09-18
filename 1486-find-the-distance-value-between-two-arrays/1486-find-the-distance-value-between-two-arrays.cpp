#include <algorithm> // For sort and lower_bound

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // Sort arr2 for binary search
        sort(arr2.begin(), arr2.end());
        
        int count = 0;
        for (int i = 0; i < arr1.size(); i++) {
            // Perform binary search to find the closest element in arr2
            auto it = lower_bound(arr2.begin(), arr2.end(), arr1[i]);
            
            // Check the closest element on the right (if exists)
            bool isValid = true;
            if (it != arr2.end() && abs(*it - arr1[i]) <= d) {
                isValid = false;
            }
            
            // Check the closest element on the left (if exists)
            if (it != arr2.begin() && abs(*(it - 1) - arr1[i]) <= d) {
                isValid = false;
            }
            
            // If no element in arr2 is within the distance d, increment count
            if (isValid) {
                count++;
            }
        }
        
        return count;
    }
};
