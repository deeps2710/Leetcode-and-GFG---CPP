class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int x: nums){
            st.insert(x);
        }
        int longest=0;
        for(int x: st){
            if(!st.count(x-1)){//if previous element doesnt exist
                int current=x;
                int length=1;
                while(st.count(current+1)){
                    current++;
                    length++;
                }
                longest=max(length, longest);
            }
        }
        return longest;
    }
};
