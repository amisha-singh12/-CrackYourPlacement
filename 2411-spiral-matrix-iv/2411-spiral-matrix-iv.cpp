class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Step 1: Initialize the matrix with -1
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        // Step 2: Define the boundaries for spiral traversal
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        
        ListNode* current = head;
        
        // Step 3: Perform spiral traversal and fill the matrix
        while (top <= bottom && left <= right && current != nullptr) {
            // Fill the top row (left to right)
            for (int i = left; i <= right && current != nullptr; ++i) {
                matrix[top][i] = current->val;
                current = current->next;
            }
            ++top;
            
            // Fill the right column (top to bottom)
            for (int i = top; i <= bottom && current != nullptr; ++i) {
                matrix[i][right] = current->val;
                current = current->next;
            }
            --right;
            
            // Fill the bottom row (right to left)
            for (int i = right; i >= left && current != nullptr; --i) {
                matrix[bottom][i] = current->val;
                current = current->next;
            }
            --bottom;
            
            // Fill the left column (bottom to top)
            for (int i = bottom; i >= top && current != nullptr; --i) {
                matrix[i][left] = current->val;
                current = current->next;
            }
            ++left;
        }
        
        return matrix;
    }
};
