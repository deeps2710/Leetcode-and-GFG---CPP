class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=needle.size();
        int n=haystack.size();
        //LPS
        vector<int> lps(m);
        int i=1;
        int len=0;
        while(i<m){
            if(needle[i]==needle[len]){
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
        i=0;
        int j=0;
        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            if(j==m){
                return i-j;
            }else if(i<n && haystack[i]!=needle[j]){
                if(j!=0){
                    j=lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return -1;
    }
};
