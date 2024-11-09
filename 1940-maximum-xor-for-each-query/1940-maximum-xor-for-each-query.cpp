class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();

        vector<int> result(n);
        // 1. find the total xor
        int  XOR = 0;
        for(int i = 0 ; i < n ; i++){
           XOR ^= nums[i];
        }

        // 2. find flip , first find the mask having all bits set ot its 1s
         int mask = ((1 << maximumBit) - 1);

         for(int i = 0; i < n ; i++){
            int k = XOR ^ mask; //this will return flipped value of xor i.e our best k
            result[i] = k;

            XOR = (XOR^ nums[n-1 -i] );
       }
       return result;
    }
};