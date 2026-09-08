class Solution {
  public:
    char firstRep(string s) {
        // Approach 1: HashMap
        unordered_map<char, int> freq;
        for(char ch: s){
            freq[ch]++;
        }
        for(char ch: s){
            if(freq[ch]>1){
                return ch;
            }
        }
        return '#';
        
        //Approach 2: Frequency Array
        vector<int> freq(26,0);
        for(char ch: s){
            freq[ch-'a']++;
        }
        for(char ch: s){
            if (freq[ch-'a']>1){
                return ch;
            }
        }
        return '#';
    }
};
