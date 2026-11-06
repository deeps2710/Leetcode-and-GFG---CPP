class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int maxVowels(string s, int k) {
        int maxcount=0;
        int currcount=0;
        int left=0;
        for(int right=0; right<s.length(); right++){
            if (isVowel(s[right])){
                currcount++;
            }
            if(right-left+1==k){
                maxcount=max(maxcount, currcount);
                if(isVowel(s[left])){
                    currcount--;
                }
                left++;
            }
        }
        return maxcount;
    }
};
