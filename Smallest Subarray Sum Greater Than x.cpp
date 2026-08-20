class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int minLen=INT_MAX;
        int left=0;
        int right=0;
        int sum=0;
        for(int i=right; right<arr.size(); right++){
            sum+=arr[right];
            while(sum>x){
                minLen=min(minLen, right-left+1);
                sum-=arr[left];
                left++;
            }
            
        }
        if(minLen==INT_MAX){
            return 0;
        }else{
            return minLen;
        }
    }
};
