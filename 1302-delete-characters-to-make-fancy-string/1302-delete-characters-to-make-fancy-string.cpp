class Solution {
public:
    string makeFancyString(string s) {
        int write_index = 1; // Position to write the next character
        int count = 1; // Counter for consecutive characters

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                count = 1; // Reset counter for a new character
            }

            // If there are fewer than 3 consecutive characters, we "write" it in place
            if (count < 3) {
                s[write_index] = s[i];
                write_index++;
            }
        }

        // Resize the string to only include valid characters
        s.resize(write_index);
        return s;
    }
};
