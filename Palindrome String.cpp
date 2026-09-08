class Solution {
  public:
    bool isPalindrome(string& s) {
        string s1=s;
        reverse(s1.begin(),s1.end());
        if(s1==s){
            return true;
        }else{
            return false;
        }
    }
};
