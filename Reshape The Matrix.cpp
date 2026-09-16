class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size();
        int n=mat[0].size();
        if(m*n!=r*c){
            return mat;
        }
        vector<vector<int>> ans(r,vector<int>(c));
        for(int i=0; i<m*n; i++){
            int r1=i/n;
            int c1=i%n;
            int r2=i/c;
            int c2=i%c;

            ans[r2][c2]=mat[r1][c1];
        }
        return ans;
    }
};
