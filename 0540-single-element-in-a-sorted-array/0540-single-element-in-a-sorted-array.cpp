class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       int  s = 0 , e = nums.size()-1;
       while(s < e){
        int mid = s +(e-s)/2;
        if(mid % 2 == 1) mid--;

        if(nums[mid] != nums[mid+1]){
            // mtlb it will be on the left side
            e = mid;
        }
        else{
            // ie it would be on the right side
            s = mid+2;
            // +2 coz we want to skip both lements pairs
        }
       }
       return nums[s];
    }
};