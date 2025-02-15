class Solution {
public:
int  t[101];
   int solve(int n ,vector<int>& nums , int i ){
    if(i >= n )return 0;
    if(t[i] != -1) return t[i];
    int steal = nums[i] + solve(n , nums , i+2);
    int skip =  solve(n , nums , i+1);

    return t[i] = max(steal ,skip);
   }
    int rob(vector<int>& nums) {
      int n = nums.size();
      memset(t  ,-1, sizeof(t));
      return solve(n , nums , 0);  
    }
};