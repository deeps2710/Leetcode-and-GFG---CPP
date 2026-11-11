class Solution {
public:
    void backtrack(int start, int target, vector<int>& candidates, vector<int>& curr, vector<vector<int>>& ans){
        //found a valid combination
        if(target==0){
            ans.push_back(curr);
            return;
        }
        int n=candidates.size();
        for(int i=start; i<n; i++){
            if(candidates[i]>target){
                continue;
            }
            //choose
            curr.push_back(candidates[i]);
            //explore
            backtrack(i, target-candidates[i], candidates, curr, ans);
            //undo
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0, target, candidates, curr, ans);
        return ans;
    }
};
