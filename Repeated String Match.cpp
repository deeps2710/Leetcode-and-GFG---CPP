class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int m=b.size();
        int len=0;
        int i=1;
        vector<int> lps(m);
        while(i<m){
            if(b[i]==b[len]){
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

        string s="";
        int count=.0;
        while(s.size()<b.size()+a.size()){
            s+=a;
            count++;
            int n=s.size();
            i=0;
            int j=0;
            while(i<n){
                if(s[i]==b[j]){
                    i++;
                    j++;
                }
                if(j==m){
                    return count;
                    
                }else if(i<n && s[i]!=b[j]){
                    if(j!=0){
                        j=lps[j-1];
                    }else{
                        i++;
                    }
                }
            }
        }
        return -1;
    }
};
