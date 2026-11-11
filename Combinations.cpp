class Solution {
public:
    void backtrack(int start, int n, int k, vector<int>& curr, vector<vector<int>>& ans){
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        int remaining=k-curr.size();
        for(int num=start; num<=n-remaining+1; num++){
            curr.push_back(num);
            backtrack(num+1, n, k, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(1, n, k, curr, ans);
        return ans;
    }
};
