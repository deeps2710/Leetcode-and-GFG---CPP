class Solution {
  public:
    int getLPSLength(string &s) {
        int i=1;
        int len=0;
        int n=s.size();
        vector<int> lps(n);
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len==0){
                    lps[i]=0;
                    i++;
                }else{
                    len=lps[len-1];
                }
            }
        }
        return lps[n-1];
    }
};
