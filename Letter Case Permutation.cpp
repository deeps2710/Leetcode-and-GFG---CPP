class Solution {
public:
    void solve(string& s, int index, vector<string>& ans){
        if(index==s.size()){
            ans.push_back(s);
            return;
        }
        if(isalpha(s[index])){
            char original=s[index];
            //choose lowercase
            s[index]=tolower(original);
            solve(s, index+1, ans);
            //choose uppercase
            s[index]=toupper(original);
            solve(s, index+1, ans);
            //backtrack
            s[index]=original;
        }else{
            solve(s, index+1, ans);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(s, 0, ans);
        return ans;
    }
};
