class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char, int> freq;
        int left=0, maxlen=-1;
        int n=s.size();
        for(int right=0; right<n; right++){
            freq[s[right]]++;
            while(freq.size()>k){
                freq[s[left]]--;
                if(freq[s[left]]==0){
                    freq.erase(s[left]);
                }
                left++;
            }
            if(freq.size()==k){
                maxlen=max(maxlen, right-left+1);
            }
        }
        return maxlen;
    }
};
