class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num;
        for(int i=0; i<nums.size();i++){
            int rem=target-nums[i];
            if(num.find(rem)!=num.end()){
                return {num[rem],i};
            }
            num[nums[i]]=i;
        }
        return {};
    }
};
