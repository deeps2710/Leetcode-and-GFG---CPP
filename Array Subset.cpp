Method 1:
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


Method 2:
class Solution {
  public:
    bool isSubset(vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i=0;
        int j=0;
        while(i<a.size()&&j<b.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return j==b.size();
    }
};
