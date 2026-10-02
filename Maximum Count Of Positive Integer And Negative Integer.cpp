class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        //Find first element >= 0 : no. of negatives
        int low=0, high=n-1, neg=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=0){
                neg=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        //Find first element > 0 : no. of positives
        low=0;
        high=n-1;
        int ind=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>0){
                ind=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        int pos=n-ind;
        return max(pos, neg);
    }
};
