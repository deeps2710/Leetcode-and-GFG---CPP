class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& curr, vector<bool>& used, vector<vector<int>>& ans){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(used[i]){
                continue;
            }
            if(i>0 && nums[i]==nums[i-1] && !used[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            used[i]=true;

            backtrack(nums, curr, used, ans);

            curr.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        vector<vector<int>> ans;
        backtrack(nums, curr, used, ans);
        return ans;
    }
};
