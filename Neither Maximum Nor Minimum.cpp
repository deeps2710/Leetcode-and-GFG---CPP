class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i: nums){
            if(i>maxi){
                maxi=i;
            }
            if(i<mini){
                mini=i;
            }
        }
        for(int i: nums){
            if(i!=maxi && i!=mini){
                return i;
            }
        }
        return -1;
    }
};
