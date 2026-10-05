class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> ans(m, vector<int>(n));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int live=0;
                for(int row=i-1; row<=i+1; row++){
                    for(int col=j-1; col<=j+1; col++){
                        if(row>=0 && row<m && col>=0 && col<n && !(row==i && col==j)){
                            if(board[row][col]==1){
                                live++;
                            }
                        }
                    }
                }

                //current cell is alive
                if(board[i][j]==1){
                    if(live==2 || live==3){
                        ans[i][j]=1;
                    }else{
                        ans[i][j]=0;
                    }
                }

                //current cell is dead
                else{
                    if(live==3){
                        ans[i][j]=1;
                    }else{
                        ans[i][j]=0;
                    }
                }
            }
        }
        board=ans;
    }
};
