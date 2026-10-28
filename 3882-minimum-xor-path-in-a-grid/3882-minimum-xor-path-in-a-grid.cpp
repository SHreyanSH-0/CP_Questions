class Solution {
public:
    int rec(vector<vector<int>>& grid, int i, int j,vector<vector<vector<int>>> &dp, int x){
        if(i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0) return 1e8;
        if(i == grid.size() - 1 && j == grid[0].size() - 1) return x^grid[i][j];
        if(dp[i][j][x] != -1) return dp[i][j][x];
        int ans = 0;
        ans = min(rec(grid,i+1,j,dp,x^grid[i][j]),rec(grid,i,j+1,dp,x^grid[i][j]));
        return dp[i][j][x] = ans; 
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m,vector<int>(1024,-1)));
        ans = rec(grid,0,0,dp,0);
        return ans;
    }
};