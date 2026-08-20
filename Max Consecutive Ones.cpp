class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int maxc=0;
        for(int i: nums){
            if(i==1){
                count++;
                maxc=max(maxc,count);
            }else{
                count=0;
            }
        }
        return maxc;
    }
};
