class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        // Step 1: Calculate prefix products and store in answer array
        int prefixProduct = 1;
        for (int i = 0; i < n; ++i) {
            answer[i] = prefixProduct;
            prefixProduct *= nums[i];
        }

        // Step 2: Calculate suffix products and update the answer array
        int suffixProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] *= suffixProduct;
            suffixProduct *= nums[i];
        }

        return answer;
    }
};
