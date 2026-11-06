class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int left=0, right=arr.size()-1;
        int count=0;
        
        while(left<right){
            int sum=arr[left]+arr[right];
            if(sum==target){
                //if all elements between left and right are same
                if(arr[left]==arr[right]){
                    int n=right-left+1;
                    count+=(n*(n-1))/2;
                    break;
                }
                //count duplicates on the left and right
                int c1=1, c2=1;
                while(left<=right && arr[left]==arr[left+1]){
                    c1++;
                    left++;
                }
                while(left<=right && arr[right]==arr[right-1]){
                    c2++;
                    right--;
                }
                count+=c1*c2;
                left++;
                right--;
            }else if(sum<target){
                left++;
            }else{
                right--;
            }
        }
        return count;
    }
};
