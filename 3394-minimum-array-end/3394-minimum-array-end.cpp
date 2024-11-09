class Solution {
public:
    long long minEnd(int n, int x) {
        long long nums = x;
       for(int i = 1 ;  i<n ; i++){
        nums = (nums+1)|x;
       } 
       return nums;
    }
};