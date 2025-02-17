class Solution {
public:

   int solve(vector<int>& nums , int l ,int r  ){
    int prevofprev = 0;
    int prev = 0; 

    for(int i = l ; i <= r ; i++){
        int steal = nums[i] + prevofprev;
        int skip = prev;
         
       int temp = max(steal ,skip); 
      prevofprev = prev;
      prev =temp;
   }
   return prev;
}
    int rob(vector<int>& nums) {
      int n = nums.size(); 
      if(n == 1) return nums[0];
       if(n == 2) {
        return max(nums[0] ,nums[1]);
       }
    //   case1 taking 0th index and skippinf the last house
    int take_0thindex =  solve(nums , 0, n-2); 
       
    // case2 taking 1st index and including the last house
    int take_1stindex = solve(nums , 1 , n-1);

    return max(take_0thindex  ,  take_1stindex);
    }
};