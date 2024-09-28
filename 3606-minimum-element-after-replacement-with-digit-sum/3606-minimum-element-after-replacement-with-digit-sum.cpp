class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
       for(int i =0 ; i<n ; i++){
           int no = nums[i];
           int rem = 0;
           int sum =0 ;
        while(no > 0){
            rem = no%10;
            no = no/10;
            sum += rem;
        }
        nums[i] = sum ;
       }
       
       int min = INT_MAX;
       for(int i =0 ; i<n ; i++){
          if(nums[i] < min)
            min = nums[i];
       }

       return min;
    }
};