class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        
        // Build the monotonic decreasing stack
        for (int i = 0; i < n; ++i) {
            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }
        
        int maxWidth = 0;
        
        // Traverse from the end of the array
        for (int j = n - 1; j >= 0; --j) {
            // Pop while we have a valid ramp (nums[st.top()] <= nums[j])
            while (!st.empty() && nums[st.top()] <= nums[j]) {
                maxWidth = max(maxWidth, j - st.top());
                st.pop();
            }
        }
        
        return maxWidth;
    }
};
