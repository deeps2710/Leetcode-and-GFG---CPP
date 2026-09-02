class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> prefix=mat;
        for(int i=0; i<m; i++){
            for(int j=1; j<n; j++){
                prefix[i][j]+=prefix[i][j-1];
            }
        }
        for(int j=0; j<n; j++){
            for(int i=1; i<m; i++){
                prefix[i][j]+=prefix[i-1][j];
            }
        }

        vector<vector<int>> answer(m, vector<int>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int row1=max(0,i-k);
                int col1=max(0,j-k);
                int row2=min(m-1,i+k);
                int col2=min(n-1,j+k);

                answer[i][j]=prefix[row2][col2];
                if(row1>0){
                    answer[i][j]-=prefix[row1-1][col2];
                }
                if(col1>0){
                    answer[i][j]-=prefix[row2][col1-1];
                }
                if(row1>0 && col1>0){
                    answer[i][j]+=prefix[row1-1][col1-1];
                }
            }
        }
        return answer;
    }
};
