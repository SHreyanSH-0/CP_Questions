class Solution {
public:
    int dfs(int i,int j,vector<vector<bool>>& vis,vector<vector<int>>& grid){
        if(i>=grid.size()||j>=grid[0].size()||i<0||j<0||grid[i][j]==0||vis[i][j]) return 0;
        int ans = 1;
        vis[i][j] = true;
        ans += dfs(i+1,j,vis,grid);
        ans += dfs(i,j-1,vis,grid);
        ans += dfs(i,j+1,vis,grid);
        ans += dfs(i-1,j,vis,grid);
        return ans ;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int cnt=0;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1&&!vis[i][j]){
                    
                    cnt = max(cnt,dfs(i,j,vis,grid));
                }
            }
        }
        return cnt;
    }
};