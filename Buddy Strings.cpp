class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        //BRUTE FORCE APPROACH
        int len=s.size();
        for(int i=0; i<len; i++){
            for(int j=i+1; j<len; j++){
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;

                if(s==goal){
                    return true;
                }else{
                    char temp=s[i];
                    s[i]=s[j];
                    s[j]=temp;
                }
            }
        }
        return false;

        //FREQUENCY ARRAY
        int freq[26]={0};
        vector<int> toswap;
        for(int i=0; i<s.size(); i++){
            freq[s[i]-'a']++;
            if(s[i]!=goal[i]){
                toswap.push_back(i);
            }
        }
        if(toswap.size()==0){ //no mismatch
            for(int i=0; i<26; i++){
                if(freq[i]>=2){ //duplicate
                    return true;
                }
            }
            return false;
        }
        if(toswap.size()<2){
            return false;
        }
        int i=toswap[0];
        int j=toswap[1];
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        return s==goal;
    }
};
