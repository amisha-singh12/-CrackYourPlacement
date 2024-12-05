class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)  {
       unordered_map<int , int > mpp;
       vector<int>a;
       for(int num : nums){
        mpp[num]++;
       }
       for(auto& [key , value]: mpp){
            if(value > (nums.size()/3))
              a.push_back(key);
       }

    return a; 
    }
};  
