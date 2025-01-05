class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
      int n = s.length();
      vector<int> diff(n,0);

  // Build the difference array -> we are solving this by this diff array approach
  for(auto &query : shifts ){
    int l = query[0];
    int r = query[1];
    int dir = query[2];
     int x;
    if(dir == 0)
      x = -1;
    if(dir == 1)
     x = +1;

     diff[l] += x;
     if(r+1 < n)
       diff[r+1] -= x;
  } 

//  find cumulative sum to find the resultant change /shift in the index 
   for(int i = 1 ; i < n; i++){
    diff[i] += diff[i-1];
   }

    // now apply the shift
    for(int i = 0 ; i < n ; i++){
        int shift = diff[i] % 26; //to wrap around

        if(shift < 0){
            shift += 26 ; //to wrap around
        }
        // s[i] - 'a' = value
        // value - 'a' = character
        s[i] = (((s[i] -'a' ) + shift) % 26) + 'a';        
    }
   return s;
    }
};