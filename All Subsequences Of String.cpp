class Solution {
  public:
    void solve(string &s, int index, string curr, vector<string>& ans){
        if(index==s.size()){
            ans.push_back(curr);
            return;
        }
        //pick current character
        solve(s, index+1, curr+s[index], ans);
        //do not pick current character
        solve(s, index+1, curr, ans);
    }
    vector<string> powerSet(string &s) {
        vector<string> ans;
        solve(s, 0, "", ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
