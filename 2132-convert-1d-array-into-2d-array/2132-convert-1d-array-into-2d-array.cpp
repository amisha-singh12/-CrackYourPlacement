#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Check if it's possible to construct the m x n array
        if (original.size() != m * n) {
            return {};  // Return an empty 2D array if not possible
        }
        
        vector<vector<int>> result(m, vector<int>(n));  // Initialize the 2D array
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = original[i * n + j];  // Fill the 2D array row by row
            }
        }
        
        return result;  // Return the constructed 2D array
    }
};
