class Solution {
  public:
    void solve(string& s, int index, vector<string>& ans){
        if(index==s.size()){
            ans.push_back(s);
            return;
        }
        if(s[index]=='?'){
            //pick 0
            s[index]='0';
            solve(s, index+1, ans);
            //pick 1
            s[index]='1';
            solve(s, index+1, ans);
            //backtrack
            s[index]='?';
        }else{
            solve(s, index+1, ans);
        }
    }
    vector<string> generateStrings(string& s) {
        vector<string> ans;
        solve(s, 0, ans);
        return ans;
    }
};
