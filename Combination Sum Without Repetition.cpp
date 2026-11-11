class Solution {
  public:
    void backtrack(int start, int target, vector<int>& arr, vector<int>& curr, vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        int n=arr.size();
        for(int i=start; i<n; i++){
            if(i>start && arr[i]==arr[i-1]){
                continue;
            }
            if(arr[i]>target){
                break;
            }
            curr.push_back(arr[i]);
            backtrack(i+1, target-arr[i], arr, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> uniqueCombinations(vector<int> &arr, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        backtrack(0, target, arr, curr, ans);
        return ans;
    }
};
