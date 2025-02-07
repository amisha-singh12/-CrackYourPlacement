#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& sudoku, char val, int n) {
        for (int i = 0; i < n; i++) {
            // Row check
            if (sudoku[row][i] == val) return false;
            // Column check
            if (sudoku[i][col] == val) return false;
            // 3x3 box check
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;
            if (sudoku[boxRow][boxCol] == val) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& sudoku) {
        int n = sudoku.size();
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (sudoku[row][col] == '.') { // Empty cell
                    for (char val = '1'; val <= '9'; val++) { // Use char instead of int
                        if (isSafe(row, col, sudoku, val, n)) {
                            sudoku[row][col] = val; // Assign as character
                            if (solve(sudoku)) return true;
                            sudoku[row][col] = '.'; // Backtrack
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& sudoku) {
        solve(sudoku);
    }
};


