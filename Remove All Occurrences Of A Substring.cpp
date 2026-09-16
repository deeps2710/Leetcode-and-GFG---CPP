class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m=part.size();
        int n=s.size();
        //LPS
        vector<int> lps(m);
        int len=0;
        int i=1;
        while(i<m){
            if(part[i]==part[len]){
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
            if(s[i]==part[j]){
                i++;
                j++;
            }
            if(j==m){
                int substr=i-j;
                for(int k=substr; k+m<s.size(); k++){
                    s[k]=s[k+m];
                }
                for(int k=0; k<m; k++){
                    s.pop_back();
                }
                j=lps[j-1];
                n=s.size();
                i=substr-m;
                if(i<0){
                    i=0;
                }
                j=0;
            }else if(i<n && s[i]!=part[j]){
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return s;
    }
};
