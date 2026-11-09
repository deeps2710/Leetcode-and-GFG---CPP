class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s2.size();
        int k=s1.size();
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(char ch: s1){
            freq1[ch-'a']++;
        }
        int left=0;
        for(int right=0; right<n; right++){
            freq2[s2[right]-'a']++;
            if(right-left+1>k){
                freq2[s2[left]-'a']--;
                left++;
            }
            if(right-left+1==k){
                if(freq1==freq2){
                    return true;
                }
            }
        }
        return false;
    }
};
