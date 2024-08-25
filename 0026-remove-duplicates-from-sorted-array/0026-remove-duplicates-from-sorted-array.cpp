class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.empty()) return 0;   // check whether array is empty or not 

        int i = 0;
        for( int j = 1; j < nums.size() ; j++ ) {  // put to iteratoer to keep track

        // if they are equal then skip if not then increase i and swap its value with current j , by this all the duplicates will  be thrown backwards and only unique no with i index would be present.
           if ( nums[i] != nums[j]) {
            i++;
            nums[i] = nums[j] ;
           }
        }
        return i+1;
    }
};