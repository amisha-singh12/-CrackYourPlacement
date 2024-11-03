class Solution {
public:
    bool rotateString(string s, string goal) {
        // by checking it manually one by one method
         if (s.size() != goal.size()) {
            return false;
        }

         // Perform the rotation check
        for (int i = 0; i < s.size(); ++i) {
            // Move the first character to the end
            char firstChar = s[0];
            s.erase(s.begin()); // Remove the first character
            s.push_back(firstChar); // Append it to the end
            
            // Check if the rotated string matches goal
            if (s == goal) {
                return true;
            }
        }
         return false;
    }
};