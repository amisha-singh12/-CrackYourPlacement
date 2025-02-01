class Solution {
public:
int n;
vector<vector<int>> result;
void solve( vector<int> &nums , int index ){
    // base case
    if(index == n){
        result.push_back(nums);
        return;
    }
    unordered_set<int>uniqueset;
    for(int i=index ;i < n ;i++){
        if(uniqueset.find(nums[i]) != uniqueset.end()){
            continue;
        }

        uniqueset.insert(nums[i]);
        swap(nums[i] , nums[index]);
        solve(nums , index+1);
        swap(nums[i] , nums[index]);
    }
  }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      n = nums.size();

      solve(nums , 0);
      return result;
    }
};