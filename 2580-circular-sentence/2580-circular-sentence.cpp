class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        // rather than checking for true check for false than it will not return premature true
        if(sentence[0] != sentence[n-1])
            return false;
       for(int i = 0; i< n ; i++){
            if( (sentence[i] == ' ') && (sentence[i-1] != sentence[i+1]) ){
               return false;
            }
       } 
       return true;
    }
};