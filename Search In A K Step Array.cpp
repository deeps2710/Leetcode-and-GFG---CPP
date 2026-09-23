class Solution {
  public:
    int findStepKeyIndex(vector<int>& arr, int k, int x) {
        int i=0;
        while(i<arr.size()){
            if(arr[i]==x){
                return i;
            }
            i+=max(1,abs((x-arr[i])/k));
        }
        return -1;
    }
};
