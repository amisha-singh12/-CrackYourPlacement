class Solution {
public:
  int n ;
int t[1001][1001];
int list(vector<vector<int>>& nums , int prev_idx , int curr_idx){
    if(curr_idx == n) return 0 ;

    if(prev_idx != -1 && t[prev_idx][curr_idx] != -1){
        return t[prev_idx][curr_idx] ;
    }
    int taken = 0 ; 
    if(prev_idx == -1 || nums[curr_idx][0] > nums[prev_idx][1]){
        taken = 1 + list(nums, curr_idx , curr_idx +1);
    }
    int skip = list(nums , prev_idx , curr_idx+1);

    if(prev_idx != -1){
        t[prev_idx][curr_idx]  = max(taken , skip);
    }
    return max(taken ,skip);

}
    int findLongestChain(vector<vector<int>>& pairs) {
      memset(t ,-1 ,sizeof(t));
      n = pairs.size();
      sort(pairs.begin() , pairs.end());
      return list(pairs, -1 , 0 );   
    }
};