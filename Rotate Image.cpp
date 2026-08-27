class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int temp;
                temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
            for (int k=0; k<n/2; k++) {
                int temp=matrix[i][k];
                matrix[i][k]= matrix[i][n-k-1];
                matrix[i][n-k-1]=temp;
            }
            
        }

        //Extra Array Approach
        vector<vector<int>> temp(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                temp[j][n-1-i]=temp[i][j];
            }
        }
        return temp;
    }
};
