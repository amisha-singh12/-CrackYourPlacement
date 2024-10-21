class Solution {
public:
    void sortColors(vector<int>& nums) {
       int count0 = 0 ;  
       int count1 = 0 ;  
       int count2 = 0 ; 
        // first iteration we will simply count the no of occurences
       for(int i = 0; i < nums.size() ; i++){
        if(nums[i] == 0)
          count0++;
        else if(nums[i] == 1)
          count1++;
        else
         count2++;
       } 

    //    in second count  we append the array basis on its count
    // for loop ke andar karenge toh o(n*m) ho jayega isliye we will append them one by one

    int index = 0;
    for(int i = 0; i < count0 ; i++){
      nums[index]= 0;
      index++;
    }  
     for(int i = 0; i < count1 ; i++){
      nums[index]= 1;
      index++;
    } 
     for(int i = 0; i < count2 ; i++){
      nums[index]= 2;
      index++;
    } 

    }
};