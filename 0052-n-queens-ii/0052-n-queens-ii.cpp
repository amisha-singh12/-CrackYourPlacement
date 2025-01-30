class Solution {
public:
    int count = 0;
    unordered_set<int> cols, diag, antidiag;
    int N;

    void solve(int row) {
        if (row == N) {  
            count++; // Found a valid arrangement
            return;
        }

        for (int col = 0; col < N; col++) {
            int diagID = row + col;
            int antiDiagID = row - col;

            if (cols.count(col) || diag.count(diagID) || antidiag.count(antiDiagID)) {
                continue;
            }

            // Place queen
            cols.insert(col);
            diag.insert(diagID);
            antidiag.insert(antiDiagID);

            solve(row + 1);  // Move to the next row

            // Backtrack
            cols.erase(col);
            diag.erase(diagID);
            antidiag.erase(antiDiagID);
        }
    }

    int totalNQueens(int n) {
        N = n;
        solve(0);
        return count;
    }
};
