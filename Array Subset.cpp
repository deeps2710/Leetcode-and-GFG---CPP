class Solution {
  public:
    bool isSubset(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> freq;
        for(int i: a){
            freq[i]+=1;
        }
        for(int i: b){
            if((freq[i]==0) || (freq.find(i)==freq.end())){
                return false;
            }
            freq[i]-=1;
        }
        return true;
    }
};
