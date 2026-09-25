class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n=arr.size();
        
        vector<int> asc=arr;
        sort(asc.begin(), asc.end());
        
        unordered_map<int, int> index;
        int ans=0;
        
        for(int i=0; i<n; i++){
            index[arr[i]]=i;
        }
        
        for(int i=0; i<n; i++){
            if(arr[i]==asc[i]){
                continue;
            }
            
            int j=index[asc[i]];
            int wrong=arr[i];
            int correct=arr[j];
            
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            
            index[correct]=i;
            index[wrong]=j;
            ans++;
        }
        return ans;
    }
};
