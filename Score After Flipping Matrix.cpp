class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        //Make first column all 1s
        for(int i=0; i<m; i++){
            if(grid[i][0]==0){
                for(int j=0; j<n; j++){
                    grid[i][j]=1-grid[i][j];
                }
            }
        }

        //for every remaining column
        //make no. of 1s max
        for(int j=1; j<n; j++){
            int ones=0;
            for(int i=0; i<m; i++){
                if(grid[i][j]==1){
                    ones++;
                }
            }
            int zeros=m-ones;
            if(zeros>ones){
                for(int i=0; i<m; i++){
                    grid[i][j]=1-grid[i][j];
                }
            }
        }

        //convert every row from binary to decimal
        int score=0;
        for(int i=0; i<m; i++){
            int value=0;
            for(int j=0; j<n; j++){
                value=value*2+grid[i][j];
            }
            score+=value;
        }
        return score;
    }
};
