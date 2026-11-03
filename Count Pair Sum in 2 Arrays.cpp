class Solution {
  public:
    int countPairs(vector<int>& a, vector<int>& b, int x) {
        int left=0;
        int right=b.size()-1;
        int count=0;
        while(left<a.size() && right>=0){
            int sum=a[left]+b[right];
            if(sum==x){
                count++;
                left++;
                right--;
            }else if(sum<x){
                left++;
            }else{
                right--;
            }
        }
        return count;
    }
};
