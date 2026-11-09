class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int left=0, sum=0;
        int ans=INT_MAX;
        for(int right=0; right<arr.size(); right++){
            sum+=arr[right];
            while(sum>x){
                ans=min(ans, right-left+1);
                sum-=arr[left];
                left++;
            }
        }
        return ans==INT_MAX? 0: ans;
    }
};
