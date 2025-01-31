class Solution {
public:
int n;
vector<vector<int>> result;
void solve(unordered_map<int , int> &mp , vector<int> & temp ){
    // base case
    if(temp.size() == n){
        result.push_back(temp);
        return;
    }
    for(auto& [num , count] :mp){
        if(count == 0){
            continue;
        }
        // do something
        temp.push_back(num);
        mp[num]--;
        // explore
        solve(mp , temp);
        // undo
        temp.pop_back();
        mp[num]++;
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      n = nums.size();
      unordered_map<int , int> mp;
      for(int &num: nums){
        mp[num]++;
      }  
      vector<int> temp;
      solve(mp,temp);
      return result;
    }
};