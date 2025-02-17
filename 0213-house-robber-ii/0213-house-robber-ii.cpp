class Solution {
public:
    long long rob(vector<int>& nums) {
      int n = nums.size() ;
       if(n ==1 ) return  nums[0];
      
      vector<int> t(n+1 , 0);
    //   t[i] money churai hai if have i houses
      t[0] = 0;
    
    // case1 first house ko take kiya last ko skip
    for(int i =1 ; i <= n-1 ;i++){
        int skip = t[i-1];
        int steal = nums[i-1] + ((i-2 >= 0) ? t[i-2] : 0);
        t[i] = max (steal ,skip);
    } 
    int result1 = t[n-1];
    t.clear();

    // case2 first house ko skip kiya last ko take
        t[0] = 0;
        t[1] = 0; //skip ist house
    for(int i = 2 ; i <= n ;i++){
        int skip = t[i-1];
        int steal = nums[i-1] + ((i-2 >= 0) ? t[i-2] : 0);
         t[i] = max (steal ,skip);
    } 
    int result2 = t[n];
   
    return max(result1 , result2);
    }
};