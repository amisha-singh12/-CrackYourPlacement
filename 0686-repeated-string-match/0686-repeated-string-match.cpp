#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    const int PRIME = 101;  // Prime number for hashing

    // Function to calculate hash value of a string
    long long computeHash(const string &s, int len) {
        long long hash = 0, power = 1;
        for (int i = 0; i < len; i++) {
            hash = (hash * PRIME + s[i]) % INT_MAX;
            power = (power * PRIME) % INT_MAX;
        }
        return hash;
    }

    // Function to check if b is a substring of repeated a using Rabin-Karp
    int repeatedStringMatch(string a, string b) {
        int minRepeats = (b.size() + a.size() - 1) / a.size(); // ceil(b.size() / a.size())
        string repeatedA = "";

        for (int i = 0; i < minRepeats; i++) {
            repeatedA += a;
        }

        // Compute hash of b
        long long hashB = computeHash(b, b.size());

        // Compute rolling hash for repeatedA
        long long hashA = computeHash(repeatedA, b.size());
        long long power = 1;

        // Precompute the power for highest digit place
        for (int i = 0; i < b.size() - 1; i++) {
            power = (power * PRIME) % INT_MAX;
        }

        // Rabin-Karp rolling hash comparison
        for (int i = 0; i <= repeatedA.size() - b.size(); i++) {
            if (hashA == hashB && repeatedA.substr(i, b.size()) == b) {
                return minRepeats;
            }
            
            // Slide the window to next substring
            if (i < repeatedA.size() - b.size()) {
                hashA = (hashA - repeatedA[i] * power) % INT_MAX;
                hashA = (hashA * PRIME + repeatedA[i + b.size()]) % INT_MAX;
                if (hashA < 0) hashA += INT_MAX;
            }
        }

        // Keep repeating until it contains b
        while (repeatedA.size() < b.size() + a.size()) {
            repeatedA += a;
            minRepeats++;

            // Check if b is now a substring
            if (repeatedA.find(b) != string::npos) {
                return minRepeats;
            }
        }

        return -1;
    }
};

