class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int>> st;
    vector<int> ans;
    int n = nums.size(); 
    for(int i = 0 ; i < n ; i++ ){
        for(int j = i+1 ; j < n ; j++){
            set<long long> hashset;
            for(int k =j+1 ; k < n ; k++){
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long fourth = target - sum;
                    if(hashset.find(fourth) != hashset.end()){
                        ans = {nums[i] , nums[j] , nums[k] , static_cast<int>(fourth)};
                        sort(ans.begin() , ans.end());
                        st.insert(ans);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
    vector<vector<int>>result(st.begin() , st.end());
    return result;
    }
};