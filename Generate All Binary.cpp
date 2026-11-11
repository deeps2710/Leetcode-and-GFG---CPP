class Solution {
  public:
    void generate(int n, string& curr, vector<string>& ans){
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }
        //choose 0
        curr.push_back('0');
        generate(n, curr, ans);
        curr.pop_back();
        //choose 1
        curr.push_back('1');
        generate(n, curr, ans);
        curr.pop_back();
    }
    vector<string> binstr(int n) {
        vector<string> ans;
        string curr="";
        generate(n, curr, ans);
        return ans;
    }
};
