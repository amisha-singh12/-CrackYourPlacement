class Solution {
public:
   vector<vector<string>>result;
     unordered_set<int> cols;
     unordered_set<int> diag;
     unordered_set<int> antidiag;
   int N;


    void solve(vector<string>& board , int row){
      if(row  >= N){
         result.push_back(board);
         return;
        }
     for(int col = 0 ; col < N ; col++){
        int diagcons = row+col;
        int antidiagcons = row-col;
        if(cols.find(col) != cols.end() || diag.find(diagcons) != diag.end()  ||  antidiag.find(antidiagcons) != antidiag.end()){
           continue;
        }
        cols.insert(col);
        diag.insert(diagcons);
        antidiag.insert(antidiagcons);
        board[row][col] = 'Q';

        solve(board ,row+1);

        cols.erase(col);
        diag.erase(diagcons);
        antidiag.erase(antidiagcons);
        board[row][col] = '.';
     }
}
    vector<vector<string>> solveNQueens(int n) {
       N= n ;
       vector<string> board(n,string(n , '.'));   // if n =3 (... , ... , ...)
       solve(board , 0 );
       return result; 
    }
};