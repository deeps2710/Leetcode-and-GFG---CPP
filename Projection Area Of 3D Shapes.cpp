class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int area=0;
        for(int i=0; i<n; i++){
            int rmax=0;
            int cmax=0;
            for(int j=0; j<n; j++){
                if(grid[i][j]>0){
                    area+=1;
                }
                rmax=max(rmax, grid[i][j]);
                cmax=max(cmax, grid[j][i]);
            }
            area+=rmax+cmax;
        }
        return area;
    }
};
