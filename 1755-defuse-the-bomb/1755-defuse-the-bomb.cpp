#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        
        if (k == 0) {
            return result; // All zeros when k is 0.
        }
        
        int direction = k > 0 ? 1 : -1; // Determine direction.
        k = abs(k); // Work with positive k for simplicity.
        
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = 1; j <= k; ++j) {
                int index = (i + j * direction + n) % n; // Circular indexing.
                sum += code[index];
            }
            result[i] = sum;
        }
        
        return result;
    }
};
