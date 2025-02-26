class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int minRepeats = (b.size() + a.size() - 1) / a.size();  // ceil(b.size() / a.size())
        string repeatedA = "";
        
        for (int i = 0; i < minRepeats; i++) {
            repeatedA += a;
        }
        
        if (repeatedA.find(b) != string::npos) return minRepeats;
        
        repeatedA += a;  // One more repetition
        if (repeatedA.find(b) != string::npos) return minRepeats + 1;
        
        return -1;
    }
};
