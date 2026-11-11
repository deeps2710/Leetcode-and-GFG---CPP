class Solution {
  public:
    void backtrack(string& s, string& curr, vector<bool>& used, vector<string>& ans){
        if(curr.size()==s.size()){
            ans.push_back(curr);
            return;
        }
        int n=s.size();
        for(int i=0; i<n; i++){
            //already used in curr
            if(used[i]){
                continue;
            }
            //skip duplicate values
            if(i>0 &&s[i]==s[i-1] && !used[i-1]){
                continue;
            }
            //choose
            curr.push_back(s[i]);
            used[i]=true;
            //explore
            backtrack(s, curr, used, ans);
            //backtrack
            curr.pop_back();
            used[i]=false;
        }
        
    }
    vector<string> findPermutation(string &s) {
        sort(s.begin(), s.end());
        string curr="";
        vector<bool> used(s.size(), false);
        vector<string> ans;
        backtrack(s, curr, used, ans);
        return ans;
    }
};
