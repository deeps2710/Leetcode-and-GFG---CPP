class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen=INT_MAX;
        int left=0;
        int right=0;
        int sum=0;
        for(int i=right; right<nums.size(); right++){
            sum+=nums[right];
            while(sum>=target){
                minLen=min(minLen,right-left+1);
                sum=sum-nums[left];
                left++;
            }
        }
        if(minLen==INT_MAX){
            return 0;
        }else{
            return minLen;
        }
    }
};
