class Solution {
public:
    int minChanges(string s) {
     int n = s.size();
     int count = 0; 
     char ch = s[0];
     int changes = 0;

     for(int i =0 ; i< n ; i++){
        if(s[i] == ch){
            count++;
            continue;
        }
        // current ch is not equal to ch
        else{
            if(count%2 == 0){  // previous substing is even len
               count =1; // start a new substring
            }
            else{
                // s[i] ko change akrna padega to make even len substring
                changes += 1;
                count =0 ;
            }
        }
        ch = s[i];
     }  
     return changes; 
    }
};