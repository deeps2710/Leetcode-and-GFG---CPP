class Solution {
public:
    void merge(vector<pair<int, string>>& arr, int low, int mid, int high){
        vector<pair<int, string>> temp;
        int left=low;
        int right=mid+1;

        while(left<=mid && right<=high){
            if(arr[left].first>=arr[right].first){
                temp.push_back(arr[left]);
                left++;
            }else{
                temp.push_back(arr[right]);
                right++;
            }
        }

        //remaining elements of left half
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }

        //remaining elements of right half
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i=low; i<=high; i++){
            arr[i]=temp[i-low];
        }
    }

    void mergeSort(vector<pair<int, string>>& arr, int low, int high){
        if(low>=high){
            return;
        }
        int mid=low+(high-low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        vector<pair<int,string>> arr;

        for (int i=0; i<n; i++) {
            arr.push_back({heights[i],names[i]});
        }
        mergeSort(arr, 0, n-1);
        vector<string> ans;
        for (int i=0; i<n; i++) {
            ans.push_back(arr[i].second);
        }

        return ans;
    }
};
