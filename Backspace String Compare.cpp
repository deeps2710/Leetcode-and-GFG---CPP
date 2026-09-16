class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ans1="";
        string ans2="";
        for(char ch: s){
            if(ch!='#'){
                ans1+=ch;
            }else if(ch=='#' && !ans1.empty()){
                ans1.pop_back();
            }
        }
        for(char ch: t){
            if(ch!='#'){
                ans2+=ch;
            }else if(ch=='#' && !ans2.empty()){
                ans2.pop_back();
            }
        }
        return ans1==ans2;
    }
};
