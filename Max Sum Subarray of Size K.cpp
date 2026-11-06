class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        long long currsum=0;
        long long maxsum=0;
        int left=0;
        for(int right=0; right<n; right++){
            currsum+=arr[right];
            //once size k is reached
            if(right-left+1==k){
                maxsum=max(currsum,maxsum);
                currsum-=arr[left];
                left++;
            }
        }
        return maxsum;
    }
};
