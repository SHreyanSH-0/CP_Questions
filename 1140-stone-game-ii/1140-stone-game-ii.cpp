class Solution {
public:
    int dp[100][101][2];
    int rec(vector<int>& piles, int i , int m , int turn){
        if(i >= piles.size()) return 0;
        if(dp[i][m][turn] != -1) return dp[i][m][turn];
        int ans = -1e8;
        if(turn == 0){
            int sum = 0;
            for(int j=0;j<2*m && i+j <piles.size();j++){
                sum += piles[i+j];
                ans = max(ans , sum + rec(piles,i+j+1, max(m , j + 1),1));
            }
            return ans;
        }
        else {
            ans = 1e8;
            for(int j=0;j<2*m && i+j <piles.size();j++){
                ans = min(ans , rec(piles,i+j+1, max(m , j + 1),0));
            }
        }

        return dp[i][m][turn]=ans;
    }

    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        int ans = rec(piles , 0, 1, 0);
        return ans;
    }
};