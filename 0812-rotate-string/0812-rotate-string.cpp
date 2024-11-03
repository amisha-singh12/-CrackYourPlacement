class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()){
            return false;
        }

    // rather than checking each term manually by appending and deleting we can use afollow up approach
    //  in this we will simply Concatenate the string s with itself (s += s) allows us to cover all possible rotations in one step. 
    // if goal is substing than its ture otherwise false

    s += s ;

     // Check if goal is a substring of the concatenated string
        return s.find(goal) != string::npos;
    }
};