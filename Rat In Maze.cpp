class Solution {
  public:
    void dfs(int r, int c, vector<vector<int>>& maze, string& path, vector<string>& ans){
        int n=maze.size();
        //reached destination
        if(r==n-1 && c==n-1){
            ans.push_back(path);
            return;
        }
        //mark current cell visited
        maze[r][c]=0;
        //directions: D,L,R,U
        string dir="DLRU";
        int dr[4]={1,0,0,-1};
        int dc[4]={0,-1,1,0};
        for(int i=0; i<4; i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            //check boundaries and availability
            if(nr>=0 && nr<n && nc>=0 && nc<n && maze[nr][nc]==1){
                //choose direction
                path.push_back(dir[i]);
                //explore
                dfs(nr, nc, maze, path, ans);
                //undo direction
                path.pop_back();
            }
        }
        //restore current cell
        maze[r][c]=1;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        int n=maze.size();
        if(n==0 || maze[0][0]==0 || maze[n-1][n-1]==0){
            return ans;
        }
        string path;
        dfs(0, 0, maze, path, ans);
        return ans;
    }
};
