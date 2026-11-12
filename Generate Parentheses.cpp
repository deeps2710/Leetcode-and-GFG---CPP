class Solution {
public:
    void backtrack(int open, int close, int n, string& curr, vector<string>& ans){
        //all parentheses have been used
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;
        }
        //choice 1: add an opening bracket
        if(open<n){
            curr.push_back('(');
            backtrack(open+1, close, n, curr, ans);
            curr.pop_back();
        }
        //choice 2: add a closing bracket
        if(close<open){
            curr.push_back(')');
            backtrack(open, close+1, n, curr, ans);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        backtrack(0,0, n, curr, ans);
        return ans;
    }
};
