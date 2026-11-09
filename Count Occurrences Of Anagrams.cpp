class Solution {
  public:
    int search(string &pat, string &txt){
        int n=txt.size();
        int k=pat.size();
        vector<int> freqpat(26,0);
        vector<int> freqwin(26,0);
        for(char ch: pat){
            freqpat[ch-'a']++;
        }
        int left=0;
        int count=0;
        for(int right=0; right<n; right++){
            freqwin[txt[right]-'a']++;
            if(right-left+1>k){
                freqwin[txt[left]-'a']--;
                left++;
            }
            if(right-left+1==k){
                if(freqpat==freqwin){
                    count++;
                }
            }
        }
        return count;
    }
};
