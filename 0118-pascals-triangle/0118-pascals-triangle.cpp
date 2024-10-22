class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // Initialize a vector of vectors to store Pascal's Triangle
        vector<vector<int>> triangle;

        // Loop through each row from 0 to numRows-1
        for (int i = 0; i < numRows; i++) {
            // Create a row filled with 1's of size i+1
            vector<int> row(i + 1, 1);

            // Fill in the middle elements (if any) by summing the two elements from the row above
            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            // Add the row to the triangle
            triangle.push_back(row);
        }

        return triangle;
    }
};
