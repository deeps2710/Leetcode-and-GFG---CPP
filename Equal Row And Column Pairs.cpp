class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int count=0;
        unordered_map<string, int> mp;

        for(int i=0; i<n; i++){
            string s="";
            for(int j=0; j<n; j++){
                s+=to_string(grid[i][j])+'_';
            }
            mp[s]++;
        }
        for(int j=0; j<n; j++){
            string s="";
            for(int i=0; i<n; i++){
                s+=to_string(grid[i][j])+'_';
            }
            count+=mp[s];
        }
        return count;
    }
};
