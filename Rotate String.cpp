class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0; i<s.length(); i++){
            string s1="";
            s1+=s.substr(i)+s.substr(0,i);
            if(s1==goal){
                return true;
            }
        }
        return false;
    }
};
