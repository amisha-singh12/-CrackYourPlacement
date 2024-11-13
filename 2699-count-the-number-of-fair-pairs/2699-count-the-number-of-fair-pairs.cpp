class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
      int n = nums.size();
      sort(nums.begin() , nums.end()) ;

      long long result = 0;
      for(int i = 0 ; i < n ; i++ ) {
        // gives the first element not less than (lower - nums[i])
        auto idx = lower_bound(begin(nums) + i + 1 , end(nums) , lower-nums[i]) - begin(nums);;
        int x = idx -1 -i ;
          // gives the first element greater than (upper - nums[i])
        idx = upper_bound(begin(nums) + i + 1 , end(nums) , upper-nums[i]) - begin(nums);
        int y = idx -1- i;
        result += (y-x);
      } 
      return result;
    }
};