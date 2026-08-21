class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int r=0, l=0;
        vector<int> ans;
        int n=arr.size();
        queue<int> q;
        while(r<n){
            if(arr[r]<0){
                q.push(arr[r]);
            }
            if(r-l+1==k){
                if(q.empty()){
                    ans.push_back(0);
                }else{
                    ans.push_back(q.front());
                }
                if(arr[l]==q.front()){
                    q.pop();
                }
                l++;
            }
            r++;
        }
        return ans;
        
    }
};
