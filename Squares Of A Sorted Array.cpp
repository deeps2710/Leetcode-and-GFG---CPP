class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> arr(nums.size());
        int left=0;
        int right=nums.size()-1;
        for(int i=nums.size()-1; i>=0; i--){
            int leftsquare=nums[left]*nums[left];
            int rightsquare=nums[right]*nums[right];
            if(leftsquare>rightsquare){
                arr[i]=leftsquare;
                left++;
            }else{
                arr[i]=rightsquare;
                right--;
            }
        }
        return arr;
    }
};
