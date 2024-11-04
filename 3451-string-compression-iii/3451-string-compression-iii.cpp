#include <string>
using namespace std;

class Solution {
    public: 
     string compressedString(string word) {
        string comp = "";
        int n = word.length();
        int i = 0;

        while(i < n){
            char cur_char = word[i];
            int count = 0;

            // Count occurrences of the current character
            while (i < n && count < 9 && word[i] == cur_char) {
                count++;
                i++;
            }
            comp += to_string(count) + cur_char;
        } 
        return comp;       
    }
};