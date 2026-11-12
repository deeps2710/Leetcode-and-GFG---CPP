class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int index){
        int rows=board.size();
        int cols=board[0].size();
        //every char matched
        if(index==word.size()){
            return true;
        }
        //invalid position
        if(r<0 || c<0 || r>=rows || c>=cols){
            return false;
        }
        //char mismatched or visited cell
        if(board[r][c]!=word[index]){
            return false;
        }
        //choose: temporarily mark visited
        char original=board[r][c];
        board[r][c]='#';
        //explore four directions
        bool found=
            dfs(board, word, r+1, c, index+1) ||
            dfs(board, word, r-1, c, index+1) ||
            dfs(board, word, r, c+1, index+1) ||
            dfs(board, word, r, c-1, index+1);
        //undo even when a path succeeds
        board[r][c]=original;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols=board[0].size();
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(dfs(board, word, r, c, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};
