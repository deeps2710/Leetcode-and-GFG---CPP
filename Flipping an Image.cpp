class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m=image.size();
        int n=image[0].size();

        for(int i=0; i<m; i++){
            int left=0;
            int right=n-1;
            while(left<right){
                int temp=image[i][left];
                image[i][left]=image[i][right];
                image[i][right]=temp;
                left++;
                right--;
            }
            for(int j=0; j<n; j++){
                image[i][j]=1-image[i][j];
            }
        }
        return image;
    }
};
