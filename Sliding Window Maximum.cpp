class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=0, r=0;
        int n=nums.size();
        vector<int> ans;
        deque<int> dq;

        while(r<n){
            //removing smaller elements
            while(!dq.empty() && (nums[dq.back()]<nums[r])){
                dq.pop_back();
            }
            //storing current index
            dq.push_back(r);
            //if window becomes k
            if(r-l+1==k){
                //front is max
                ans.push_back(nums[dq.front()]);
                
                if(dq.front()==l){
                    dq.pop_front();
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};
