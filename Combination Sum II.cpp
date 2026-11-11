class Solution {
public:
    void backtrack(int start, int target, vector<int>& candidates, vector<int>& curr, vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        int n=candidates.size();
        for(int i=start; i<n; i++){
            if(i>start && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            curr.push_back(candidates[i]);
            backtrack(i+1, target-candidates[i], candidates, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates, curr, ans);
        return ans;
    }
};
