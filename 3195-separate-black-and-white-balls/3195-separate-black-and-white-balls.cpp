class Solution {
public:
    long long minimumSteps(string s) {
         // it's a more like an easy question we just need to keep count of black balls and when we encounter a white ball we jsut need to increment thhe no of swaps to no of balck balls.
        long long swap = 0;
         long long count =0;
         for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] == '1'){
                count++ ;
            }
            else{
                swap += count;
            }
         }
         return swap;
    }
};