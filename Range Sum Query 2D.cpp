class NumMatrix {
public:
    vector<vector<int>> ans;
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        ans=matrix;
        for(int i=0; i<m; i++){
            for(int j=1; j<n; j++){
                ans[i][j]+=ans[i][j-1];
            }
        }
        for(int j=0; j<n; j++){
            for(int i=1; i<m; i++){
                ans[i][j]+=ans[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=ans[row2][col2];
        if(row1>0){
            sum-=ans[row1-1][col2];
        }
        if(col1>0){
            sum-=ans[row2][col1-1];
        }
        if(row1>0 && col1>0){
            sum+=ans[row1-1][col1-1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
