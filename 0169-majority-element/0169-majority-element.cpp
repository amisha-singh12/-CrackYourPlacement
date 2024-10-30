class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int , int > mpp;
       for(int num : nums){
        mpp[num]++;
        if(mpp[num] > (nums.size())/2)
         return num;
       }
    return -1; 
    }
};