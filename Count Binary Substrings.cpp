class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev=0;
        int curr=1;
        int ans=0;
        for(int i=1; i<s.size(); i++){
            if(s[i]==s[i-1]){
                curr++;
            }else{ //new group
                ans+=min(prev,curr);
                prev=curr;
                curr=1;
            }
        }
        ans+=min(prev,curr); //for last pair left
        return ans;
    }
};
