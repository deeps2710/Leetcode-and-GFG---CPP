class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        //sum/k>=threshold ==> sum>=k*threshold
        int count=0;
        int currsum=0;
        int left=0;
        int targetsum=k*threshold;
        for(int right=0; right<arr.size(); right++){
            currsum+=arr[right];
            if(right-left+1==k){
                if(currsum>=targetsum){
                    count++;
                }
                currsum-=arr[left];
                left++;
            }
        }
        return count;
    }
};
