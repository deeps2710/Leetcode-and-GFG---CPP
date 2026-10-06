class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> maxrow(n,0);
        vector<int> maxcol(n,0);
        //max building for each row and column
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                maxrow[r]=max(maxrow[r], grid[r][c]);
                maxcol[c]=max(maxcol[c], grid[r][c]);
            }
        }
        int total=0;
        //calculate max possible increase
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                int allowed=min(maxrow[r], maxcol[c]);
                total+=allowed-grid[r][c];
            }
        }
        return total;
    }
};
