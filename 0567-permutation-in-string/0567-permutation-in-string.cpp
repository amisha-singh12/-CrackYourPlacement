class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        
        // Array to store frequency of characters
        vector<int> s1Freq(26, 0), s2Freq(26, 0);
        
        // Count frequency of characters in s1 and the first window of s2
        for (int i = 0; i < s1.length(); i++) {
            s1Freq[s1[i] - 'a']++;
            s2Freq[s2[i] - 'a']++;
        }
        
        // Sliding window
        for (int i = s1.length(); i < s2.length(); i++) {
            // If frequencies match, return true
            if (s1Freq == s2Freq) return true;
            
            // Slide the window: remove left character and add right character
            s2Freq[s2[i - s1.length()] - 'a']--;
            s2Freq[s2[i] - 'a']++;
        }
        
        // Check the last window
        return s1Freq == s2Freq;
    }
};
