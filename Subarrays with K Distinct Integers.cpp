class Solution {
  public:
    int atmostK(vector<int>& arr, int k){
        int n=arr.size();
        unordered_map<int, int> freq;
        int left=0, count=0;
        for(int right=0; right<n; right++){
            freq[arr[right]]++;
            while(freq.size()>k){
                freq[arr[left]]--;
                if(freq[arr[left]]==0){
                    freq.erase(arr[left]);
                }
                left++;
            }
            count+=right-left+1;
        }
        return count;
    }
    int exactlyK(vector<int> &arr, int k) {
        return atmostK(arr, k)-atmostK(arr, k-1);
    }
};
