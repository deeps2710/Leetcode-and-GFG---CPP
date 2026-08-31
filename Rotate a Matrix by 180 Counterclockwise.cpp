class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n; j++){
                int temp=mat[i][j];
                mat[i][j]=mat[n-1-i][n-1-j];
                mat[n-1-i][n-1-j]=temp;
            }
        }
        // If n is odd, reverse the middle row
        if(n%2!=0){
            int i=n/2; //points to middle row
            for(int j=0; j<n/2; j++){
                int temp=mat[i][j];
                mat[i][j]=mat[i][n-1-j];
                mat[i][n-1-j]=temp;
            }
        }
    }
};
