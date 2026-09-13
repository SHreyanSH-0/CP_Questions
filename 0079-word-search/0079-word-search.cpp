class Solution {
public:
    bool dfs(int idx,int i,int j,vector<vector<char>>& board, string& word,vector<vector<int>>&vis){
        int n= board.size(),m= board[0].size();
        if(idx==word.size()-1 && board[i][j]==word[idx])return true;
        if(word[idx]!=board[i][j])return false;
        vis[i][j]=1;
        if(i+1<n && !vis[i+1][j]){
            if(dfs(idx+1,i+1,j,board,word,vis))return true;
        }
        if(i-1>=0 && !vis[i-1][j]){
            if(dfs(idx+1,i-1,j,board,word,vis))return true;
        }
        if(j+1<m && !vis[i][j+1]){
            if(dfs(idx+1,i,j+1,board,word,vis))return true;
        }
        if(j-1>=0 && !vis[i][j-1]){
            if(dfs(idx+1,i,j-1,board,word,vis))return true;
        }
        vis[i][j]=0;

        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n= board.size(),m= board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(0,i,j,board,word,vis))return true;
                }
            }
        }

        return false;
    }
};