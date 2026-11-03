class Solution {
  public:
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
        int left=0;
        int right=0;
        vector<int> ans;
        while(left<arr1.size() && right<arr2.size()){
            if(arr1[left]==arr2[right]){
                if(ans.empty() || ans.back()!=arr1[left]){
                    ans.push_back(arr1[left]);
                }
                left++;
                right++;
            }else if(arr1[left]<arr2[right]){
                left++;
            }else{
                right++;
            }
        }
        return ans;
    }
};
