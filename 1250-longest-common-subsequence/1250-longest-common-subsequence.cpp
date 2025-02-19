class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> t(m+1 , vector<int>(n+1));
        // first row and col would be 0
        for(int row =0 ; row <= m ; row++ ){
            t[row][0] = 0;
        }
         for(int col =0 ; col <= n ; col++ ){
            t[0][col] = 0;
        }

        for(int i = 1 ; i <= m ; i++){
            for(int  j = 1 ; j <= n; j++){
                if(text1[i-1] == text2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j] , t[i][j-1]);
                }
            }
        }
        return t[m][n];
    }
};