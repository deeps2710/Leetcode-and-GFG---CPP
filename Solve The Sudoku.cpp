class Solution {
public:
    bool isValid(vector<vector<int>>& mat, int row, int col, int n){
        for(int i=0; i<9; i++){
            //check row
            if(mat[row][i]==n){
                return false;
            }
            //check column
            if(mat[i][col]==n){
                return false;
            }
            //check 3x3 box
            int r=3*(row/3)+i/3;
            int c=3*(col/3)+i%3;
            if(mat[r][c]==n){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<int>>& mat){
        for(int row=0; row<9; row++){
            for(int col=0; col<9; col++){
                if(mat[row][col]==0){
                    for(int n=1; n<=9; n++){
                        if(isValid(mat, row, col, n)){
                            //choose
                            mat[row][col]=n;
                            //explore
                            if(solve(mat)){
                                return true;
                            }
                            //undo
                            mat[row][col]=0;
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
    void solveSudoku(vector<vector<int>>& mat) {
        solve(mat);
    }
};
