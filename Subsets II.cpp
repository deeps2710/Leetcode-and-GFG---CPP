class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans){
        //every current subset is valid
        ans.push_back(curr);
        int n=nums.size();
        for(int i=start; i<n; i++){
            //skip duplicates at same level
            if(i>start && nums[i]==nums[i-1]){
                continue;
            }
            //choose
            curr.push_back(nums[i]);
            //explore
            backtrack(i+1, nums, curr, ans);
            //undo
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0, nums, curr, ans);
        return ans;
    }
};
