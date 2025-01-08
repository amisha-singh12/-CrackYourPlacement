#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        // Check if str1 is both a prefix and a suffix of str2
        int n = str1.length();
        int m = str2.length();
        if (n > m) return false; // str1 cannot be a prefix and suffix if it's longer than str2
        return str2.substr(0, n) == str1 && str2.substr(m - n, n) == str1;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    ++count;
                }
            }
        }
        
        return count;
    }
};
