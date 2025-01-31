class Solution {
public:
   vector<vector<int>> result;
   int n ;
   void solve(int index ,  vector<int> &nums ){
    if(index == n){
        result.push_back(nums);
        return;
    }
    for(int i = index ; i <n ;i++ ){
        swap(nums[i],nums[index]);
        solve(index+1 , nums);
        swap(nums[index],nums[i]);
    }
   }
    vector<vector<int>> permute(vector<int>& nums) {
        n =nums.size();
        solve(0 , nums);
        return result;
    }
};