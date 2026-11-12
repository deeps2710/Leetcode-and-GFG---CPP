class Solution {
public:
    void backtrack(int row, int n, vector<string>& board, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2, vector<vector<string>>& ans){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int c=0; c<n; c++){
            int d1=row-c+n-1;
            int d2=row+c;
            //queen would be attacked
            if(col[c] || diag1[d1] || diag2[d2]){
                continue;
            }
            //choose
            board[row][c]='Q';
            col[c]=true;
            diag1[d1]=true;
            diag2[d2]=true;
            //explore next row
            backtrack(row+1, n, board, col, diag1, diag2, ans);
            //undo
            board[row][c]='.';
            col[c]=false;
            diag1[d1]=false;
            diag2[d2]=false;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        vector<vector<string>> ans;
        vector<bool> col(n, false);
        vector<bool> diag1(2*n-1, false);
        vector<bool> diag2(2*n-1, false);
        backtrack(0,n, board, col, diag1, diag2, ans);
        return ans;
    }
};
