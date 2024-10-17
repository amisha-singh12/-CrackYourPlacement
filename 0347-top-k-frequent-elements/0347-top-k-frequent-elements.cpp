class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       int n = nums.size();

       unordered_map<int , int> mp;
       for(int &num : nums ) {
        mp[num]++;
       } 

       vector<vector<int>> bucket(n+1);
    //    here we are taking index as frequency and value as elements
    // ie bucket[i] = elements having i freq
    for (auto &it : mp) {
        int element = it.first;
        int freq = it.second;

        bucket[freq].push_back(element);
    }
    // for result pick elemts from right to left from bucket to find max freq 
    vector<int>  result;
    for(int i = n; i >=0 ;i-- ){
        if(bucket[i].size() == 0)
          continue;

    while(bucket[i].size() > 0 && k >0){
        result.push_back(bucket[i].back());
        bucket[i].pop_back();
        k--;
    }
   }
   return result;
    }
};