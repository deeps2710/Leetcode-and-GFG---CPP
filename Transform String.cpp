class Solution {
  public:
    int transform(string &s1, string &s2) {
        int m=s1.size()-1;
        int n=s2.size()-1;
        if(m!=n){
            return -1;
        }
        unordered_map<char, int> freq;
        for(char ch: s1){
            freq[ch]++;
        }
        for(char ch: s2){
            freq[ch]--;
        }
        for(char ch: s1){
            if (freq[ch]!=0){
                return -1;
            }
        }
        int count=0;
        while(m>=0){
            if(s1[m]==s2[n]){
                m--;
                n--;
            }else{
                count++;
                m--;
            }
        }
        return count;
    }
};
