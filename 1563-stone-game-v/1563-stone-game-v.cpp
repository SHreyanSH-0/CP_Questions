class Solution {
public:
    int dp[500][500];
    int rec(vector<int>&v, int i, int j){
        if(i >= j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long sum1 = 0, sum2 = 0;
        long long ans = 0;
        for(int k=i;k<=j;k++){
            sum1 += v[k];
        }
        for(int k=i;k<=j;k++){
            sum2 += v[k];
            sum1 -= v[k];

            if(sum1 == sum2){
                ans = max(ans, sum1 + rec(v,k+1,j));
                ans = max(ans, sum2 + rec(v,i,k));
            }
            else if(sum1 > sum2){
                ans = max(ans, sum2 + rec(v,i,k));
            }
            else{
                ans = max(ans, sum1 + rec(v,k+1,j));
            }
        }
        return dp[i][j]=ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        memset(dp,-1,sizeof(dp));
        return rec(stoneValue, 0,stoneValue.size()-1);
    }
};