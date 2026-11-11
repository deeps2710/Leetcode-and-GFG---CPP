class Solution {
public:
    void solve(vector<int>& nums, int index, vector<int>& curr, vector<vector<int>>& ans){
        if(index==nums.size()){
            ans.push_back(curr);
            return;
        }
        //pick the current element
        curr.push_back(nums[index]);
        solve(nums, index+1, curr, ans);
        //backtrack (undo the choice)
        curr.pop_back();
        //dont pick the current element
        solve(nums, index+1, curr, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(nums, 0, curr, ans);
        return ans;
    }
};
