#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        // If k is greater than the length of s, it's not possible
        if (k > s.length()) return false;

        // Count the frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Count the number of characters with odd frequencies
        int odd_count = 0;
        for (auto& [ch, count] : freq) {
            if (count % 2 != 0) {
                odd_count++;
            }
        }

        // We can construct k palindromes if odd_count <= k
        return odd_count <= k;
    }
};
