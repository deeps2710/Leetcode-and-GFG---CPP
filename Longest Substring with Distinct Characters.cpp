class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        unordered_set<char> seen;
        int left=0;
        int maxlen=0;
        for(int right=0; right<s.size(); right++){
            while(seen.count(s[right])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            maxlen=max(maxlen, right-left+1);
        }
        return maxlen;
    }
};
