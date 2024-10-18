class Solution {
public:
    int minMoves(vector<int>& nums) {
        int count = 0;
       if (nums.size() < 2)
         return 0;

        // Use std::min_element to find the smallest element
        int no = *std::min_element(nums.begin(), nums.end());
        
// rather than:
// [1,2,3] -> [2,3,3] -> [3,3,4] -> [4,4,4] = 3 moves
// We do:
// [1,2,3] -> [1,2,2] -> [1,1,2] -> [1,1,1] = 3 moves
// The logic is the same:
// Decrease 1 over Sum every but one.
    for(int i = 0 ; i < nums.size() ; i++){
    //    int  sum = nums[i] - 1 ;
        count += nums[i] - no ;
        }
        return count;
    }
};