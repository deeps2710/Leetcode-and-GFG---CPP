class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& curr, vector<bool>& used, vector<vector<int>>& ans){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        int n=nums.size();
        for(int i=0; i<n; i++){
            //already chosen in this permutation
            if(used[i]){
                continue;
            }
            //choose
            curr.push_back(nums[i]);
            used[i]=true;
            //explore
            backtrack(nums, curr, used, ans);
            //undo
            curr.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        vector<vector<int>> ans;
        backtrack(nums, curr, used, ans);
        return ans;
    }
};
