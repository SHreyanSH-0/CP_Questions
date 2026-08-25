class Solution {
public:
    int dp[201][201];
    int rec(int low, int high){
        if(low >= high) return 0;
        if(dp[low][high] != -1 )return dp[low][high];
        int ans = 1e8;

        for(int i=low;i<=high;i++){
            ans = min(ans , max(i + rec(low , i-1), i + rec(i+1,high)));
        }

        return dp[low][high]=ans;
    }

    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(1,n);
    }
};