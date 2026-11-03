class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        int n=arr.size();
        for(int i=0; i<n-2; i++){
            //skip duplicate fixed elements
            if(i>0 && arr[i]==arr[i-1]){
                continue;
            }
            int left=i+1;
            int right=n-1;
            while(left<right){
                int sum=arr[i]+arr[left]+arr[right];
                if(sum==target){
                    return true;
                    //skip duplicate left values
                    while(left<right && arr[left]==arr[left-1]){
                        left++;
                    }
                    //skip duplicate right values
                    while(left<right && arr[right]==arr[right+1]){
                        right--;
                    }
                }else if(sum<target){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return false;
    }
};
