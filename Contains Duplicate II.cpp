class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        int n=nums.size();
        for(int right=0; right<n; right++){
            if(st.find(nums[right])!=st.end()){
                return true;
            }
            st.insert(nums[right]);
            if(st.size()>k){
                st.erase(nums[right-k]);
            }
        }
        return false;
    }
};
