class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size();
        int n=img[0].size();
        vector<vector<int>> ans(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int sum=0;
                int count=0;
                for(int row=i-1; row<=i+1; row++){
                    for(int col=j-1; col<=j+1; col++){
                        if(row>=0 && row<m &&
                        col>=0 && col<n){
                            sum+=img[row][col];
                            count++;
                        }
                    }
                }
                ans[i][j]=sum/count;
            }
        }
        return ans;
    }
};
