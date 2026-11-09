class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left=0, maxlen=0;
        for(int right=0; right<s.size(); right++){
            //remove characters until duplicate is gone
            while(seen.count(s[right])){
                seen.erase(s[left]);
                left++;
            }
            //add current character
            seen.insert(s[right]);
            //update max length
            maxlen=max(maxlen, right-left+1);
        }
        return maxlen;
    }
};
