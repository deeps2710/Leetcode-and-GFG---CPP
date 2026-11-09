class Solution {
public:
    int characterReplacement(string s, int k) {
        //a window is valid if:-
        //window length - max freq <=k
        vector<int> freq(26,0);
        int left=0, maxlen=0;
        int n=s.size();
        for(int right=0; right<n; right++){
            freq[s[right]-'A']++;
            while((right-left+1)-*max_element(freq.begin(), freq.end())>k){
                freq[s[left]-'A']--;
                left++;
            }
            maxlen=max(maxlen, right-left+1);
        }
        return maxlen;
    }
};
