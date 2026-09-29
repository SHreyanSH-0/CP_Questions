class Solution {
public:
    int dp[100][100][201];
    bool rec(int i, int j,int ct, vector<vector<char>>& grid){
        if(i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0) return false;
        if(ct < 0 || ct > 200) return false;
        if(i == grid.size() - 1 && j == grid[0].size() - 1){
            int newCt = grid[i][j] == '(' ? 1 : -1;
            return ct + newCt == 0;
        }

        if(dp[i][j][ct]!=-1) return dp[i][j][ct];

        bool ans = false;

        int newCt = grid[i][j] == '(' ? 1 : -1;

        ans = ans | rec(i + 1,j,ct + newCt, grid);
        ans = ans | rec(i,j+1,ct + newCt, grid);

        return dp[i][j][ct]=ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,0,grid);
    }
};