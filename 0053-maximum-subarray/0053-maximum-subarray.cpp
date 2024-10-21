class Solution {
public:

//  applying kadane's algorithm
    int maxSubArray(vector<int>& nums) {
      int maxS = INT_MIN;
       int sum = 0;
      for(int  i = 0; i < nums.size() ; i++){
            sum += nums[i];
            maxS = max(sum  , maxS);
             if(sum < 0 ){
               sum = 0;
            }
      }
      return maxS;   
    }
};