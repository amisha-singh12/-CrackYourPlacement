class Solution {
public:
    vector<vector<int>>ans;
    void recur(vector<int> &candidates , int target ,  int current ,  vector<int>v , int curSum){
        if(curSum >target || current == candidates.size())
          return ;
        if(curSum == target) {
            ans.push_back(v);
            return;
        }

        // not choosen
        recur(candidates , target , current+1 , v , curSum);
        v.push_back(candidates[current]);
        recur(candidates , target , current , v , curSum + candidates[current]);
        v.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      recur(candidates , target , 0 , {} , 0);
       return ans;
    }
};