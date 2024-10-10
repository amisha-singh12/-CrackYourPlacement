#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0; // Tracks position to insert compressed characters
        int i = 0; // Iterates through the original array

        while (i < n) {
            char cur_char = chars[i];
            int count = 0;

            // Count occurrences of the current character
            while (i < n && chars[i] == cur_char) {
                count++;
                i++;
            }

            // Assign the current character to the result array
            chars[index] = cur_char;
            index++;

            // If the count is greater than 1, convert it to string and insert each digit
            if (count > 1) {
                string count_str = to_string(count);
                for (char ch : count_str) {
                    chars[index] = ch;
                    index++;
                }
            }
        }

        // Return the length of the  array
        return index;
    }
};
