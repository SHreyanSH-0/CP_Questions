class Solution {
public:
    int mod = 1e9 + 7;
    int dp[1000][1001][2];
    int rec(int n, int k, int i, int curr){
        if(i >= n) return (k == 0 && !curr);
        if(k == 0) return !curr;
        if(dp[i][k][curr]!=-1) return dp[i][k][curr];
        int ans = 0;

        if(!curr){
            int p = rec(n,k,i+1,1);
            int np = rec(n,k,i+1,0);
            ans = p + np;
        }
        else{
            int p = rec(n,k-1,i,0);
            int np = rec(n,k,i+1,1);

            ans = p + np;
        }

        return dp[i][k][curr] = ans%mod;
    }

    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return rec(n,k,0,0);
    }
};