class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            //remove invalid candidates
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            //find next greater element
            if(!st.empty()){
                ans[i]=st.top();
            }
            //current element may help earlier
            st.push(arr[i]);
        }
        return ans;
    }
};
