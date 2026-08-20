class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int maxsum=INT_MIN;
        int left=0;
        int sum=0;
        int right=k-1;
        for(int i=0; i<k; i++){
            sum+=arr[i];
        }
        maxsum=sum;
        while(right<arr.size()-1){
            sum-=arr[left];
            left++;
            right++;
            sum+=arr[right];
            maxsum=max(maxsum, sum);
        }
        return maxsum;
    }
};
