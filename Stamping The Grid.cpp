//BRUTE FORCE METHOD
class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> marked(m, vector<int>(n,0));

        for(int i=0; i+stampHeight<=m; i++){
            for(int j=0; j+stampWidth<=n; j++){
                bool mark=true;
                for(int r=i; r<i+stampHeight; r++){
                    for(int c=j; c<j+stampWidth; c++){
                        if(grid[r][c]==1){
                            mark=false;
                            break;
                        }
                    }
                    if(!mark){
                        break;
                    }
                }
                if(mark){
                    for(int r=i; r<i+stampHeight; r++){
                        for(int c=j; c<j+stampWidth; c++){
                            marked[r][c]=1;
                        }
                    }
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0 && marked[i][j]==0){
                    return false;
                }
            }
        }
        return true;
    }
};
