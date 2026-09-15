class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        int m=pat.size();
        int n=txt.size();
        //LPS Array
        vector<int> lps(m);
        int i=1;
        int len=0;
        while(i<m){
            if(pat[i]==pat[len]){
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
        //KMP
        vector<int> ans;
        i=0;
        int j=0;
        while(i<n){
            if(txt[i]==pat[j]){
                i++;
                j++;
            }
            if(j==m){
                ans.push_back(i-j);
                j=lps[j-1];
            }else if(i<n && txt[i]!=pat[j]){
                if(j!=0){
                    j=lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return ans;
    }
}; 
