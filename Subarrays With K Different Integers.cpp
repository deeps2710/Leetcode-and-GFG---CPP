class Solution {
public:
    int atmostK(vector<int>& nums, int k){
        if(k<0){
            return 0;
        }
        unordered_map<int, int> freq;
        int left=0, count=0;
        int n=nums.size();
        for(int right=0; right<n; right++){
            freq[nums[right]]++;
            while(freq.size()>k){
                freq[nums[left]]--;
                if(freq[nums[left]]==0){
                    freq.erase(nums[left]);
                }
                left++;
            }
            count+=right-left+1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostK(nums, k)- atmostK(nums, k-1);
    }
};
