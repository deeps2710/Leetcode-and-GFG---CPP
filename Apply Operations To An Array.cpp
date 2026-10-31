class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        for(int i=0; i<n; i++){
            //apply operation on adjacent elements
            if(i+1<n && nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
            //shift non-zero elements
            if(nums[i]!=0){
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                j++;
            }
        }
        return nums;
    }
};
