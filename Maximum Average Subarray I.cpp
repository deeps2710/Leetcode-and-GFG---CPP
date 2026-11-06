class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        long long currsum=0;
        long long maxsum=LLONG_MIN;
        for(int right=0; right<n; right++){
            currsum+=nums[right];
            if(right-left+1==k){
                maxsum=max(maxsum,currsum);
                currsum-=nums[left];
                left++;
            }
        }
        return (double)maxsum/k;
    }
};
