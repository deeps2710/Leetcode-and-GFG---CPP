class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int k=p.size();
        vector<int> freqpat(26,0);
        vector<int> freqwin(26,0);
        int left=0;
        vector<int> ans;
        for(char ch: p){
            freqpat[ch-'a']++;
        }
        for(int right=0; right<n; right++){
            freqwin[s[right]-'a']++;
            if(right-left+1>k){
                freqwin[s[left]-'a']--;
                left++;
            }
            if(right-left+1==k){
                if(freqpat==freqwin){
                    ans.push_back(left);
                }
            }
        }
        return ans;
    }
};
