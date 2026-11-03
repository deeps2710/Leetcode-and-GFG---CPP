class Solution {
public:
    static bool compare(string a, string b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(int i: nums){
            arr.push_back(to_string(i));
        }
        sort(arr.begin(), arr.end(), compare);

        //handle cases like [0,0]
        if(arr[0]=="0"){
            return "0";
        }
        string ans="";
        for(string s: arr){
            ans+=s;
        }
        return ans;
    }
};
