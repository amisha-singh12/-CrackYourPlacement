class Solution {
public:
    int rob(vector<int>& nums) {
      int n = nums.size();
    //   constant space me karenge
       if( n == 1) return nums[0];
      int prevofprev = 0;  // t[0]
       int prev = nums[0]; //t[1]

       for(int i = 2 ; i <= n ; i++){
        int steal = nums[i-1] + prevofprev;
        int skip = prev;
         
      int temp = max(steal ,skip); 
      prevofprev = prev;
      prev =temp;
    } 
       return prev ;
    }
};