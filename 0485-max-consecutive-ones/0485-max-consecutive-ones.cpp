class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int count = 0;
       int oneCount =0;
       for(int i =0 ; i <nums.size() ; i++){
       
           if(nums[i] == 1){
              oneCount++ ;
             }

            else{
               count = max(count, oneCount);
                oneCount = 0; 
               }
            }

            count = max(count, oneCount); 

        return count;
    
    }
};