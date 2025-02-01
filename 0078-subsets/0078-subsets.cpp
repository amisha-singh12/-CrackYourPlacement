class Solution {
public:
    vector<vector<int>>result;

    void solve(int i , vector<int> & nums , vector<int> & temp){
        if( i >= nums.size()){
            result.push_back(temp);
            return;
        }
        // take ith element
        temp.push_back(nums[i]); 
        // trust with element
        solve( i+1 , nums, temp);
        // remove ith element
        temp.pop_back();
        // trust without element
        solve( i+1 , nums, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<int> temp;
       solve( 0 ,  nums , temp);
       return result;

    }
};