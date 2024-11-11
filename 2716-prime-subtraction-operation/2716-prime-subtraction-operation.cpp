class Solution {
public:
    
    bool isPrime[1000];

    void sieve() {
        fill(isPrime , isPrime +1000 , true); //initalising the array ith all true
        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2 ; i*i < 1000 ; i++){
            if(isPrime[i] == true){
                for(int j = i *i; j < 1000; j += i){
                    isPrime[j] = false;
                }
            }
        }
    }
   
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();

        sieve(); // it will populate my isPrime array
        // is isPrime == true , means its prime else false
   
    //   we will strt iterating fereom backside , n-2 coz n-1 no is already the greatest as their is no comparison
        for(int i = n-2 ; i >= 0 ; i--){
            if(nums[i] < nums[i+1]) {
                continue;
            }
        // nums[i] > = nums[i+1] decrease nums[i] atlease less than nums[i+]

        // check prime no less than nums[i]

        for(int p = 2 ; p < nums[i] ; p++) {
            if(!isPrime[p]){
                continue;
            }

            if(nums[i] - p < nums[i+1]) {
                nums[i] -= p ;
                break;
            }
        }
        if(nums[i] >= nums[i+1]) {
            return false;
        }
     }
     return true;
    }
};