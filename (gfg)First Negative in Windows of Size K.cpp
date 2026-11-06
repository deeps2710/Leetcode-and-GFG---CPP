class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int right=0; right<arr.size(); right++){
            //store negative element indices
            if(arr[right]<0){
                dq.push_back(right);
            }
            //current window's left boundary
            int left=right-k+1;
            //remove outdated negative indices
            while(!dq.empty() && dq.front()<left){
                dq.pop_front();
            }
            //process only complete window
            if(right>=k-1){
                if(dq.empty()){
                    ans.push_back(0);
                }else{
                    ans.push_back(arr[dq.front()]);
                }
            }
        }
        return ans;
    }
};
