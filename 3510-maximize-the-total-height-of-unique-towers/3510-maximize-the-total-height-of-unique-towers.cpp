class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        unordered_set<long long> st;
        int n = maximumHeight.size();
        
        sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());
        
        long long ans = 0;
        long long currentMax = LLONG_MAX; 
        
        for (int i = 0; i < n; i++) {
            long long temp = maximumHeight[i];
            

            temp = min(temp, currentMax);
            
            if (temp <= 0) {
                return -1; 
            }
            
            ans += temp;
            currentMax = temp - 1;  
        }
        
        return ans;
    }
};
