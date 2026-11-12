class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch){
        for(int i=0; i<9; i++){
            //check row
            if(board[row][i]==ch){
                return false;
            }
            //check column
            if(board[i][col]==ch){
                return false;
            }
            //check 3x3 box
            int r=3*(row/3)+i/3;
            int c=3*(col/3)+i%3;
            if(board[r][c]==ch){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int row=0; row<9; row++){
            for(int col=0; col<9; col++){
                if(board[row][col]=='.'){
                    for(char ch='1'; ch<='9'; ch++){
                        if(isValid(board, row, col, ch)){
                            //choose
                            board[row][col]=ch;
                            //explore
                            if(solve(board)){
                                return true;
                            }
                            //undo
                            board[row][col]='.';
                        }
                    }
                    //no digit worked here
                    return false;
                }
            }
        }
        //no empty cells remain
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
