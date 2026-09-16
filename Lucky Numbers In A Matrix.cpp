class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> ans;
        for(int i=0; i<m; i++){
            int mini=matrix[i][0];
            int col=0;
            //find min element of a row
            for(int j=1; j<n; j++){
                if(matrix[i][j]<mini){
                    mini=matrix[i][j];
                    col=j;
                }
            }
            //check if it is max in column
            bool lucky=true;
            for(int k=0; k<m; k++){
                if(matrix[k][col]>mini){
                    lucky=false;
                    break;
                }
            }
            if(lucky){
                ans.push_back(mini);
            }
        }
        return ans;
    }
};
