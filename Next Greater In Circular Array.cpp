class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        int n=arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=2*n-1; i>=0; i--){
            int index=i%n;
            while(!st.empty() && st.top()<=arr[index]){
                st.pop();
            }
            //store answers only for original indices
            if(i<n && !st.empty()){
                ans[index]=st.top();
            }
            st.push(arr[index]);
        }
        return ans;
    }
};
