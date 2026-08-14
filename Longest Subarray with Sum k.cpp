class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> cf;
        int sum=0;
        int length=0;
        for(int i=0; i<arr.size(); i++){
            sum+=arr[i];
            // subarray from index 0 to i
            if(sum==k){
                length=i+1;
            }
            //if prefix sum(sum-k) was seen before
            if(cf.find(sum-k)!=cf.end()){
                int len=i-cf[sum-k];
                length=max(length, len);
            }
            //store only first occurrence
            if(cf.find(sum)==cf.end()){
                cf[sum]=i;
            }
        }
        return length;
    }
};
